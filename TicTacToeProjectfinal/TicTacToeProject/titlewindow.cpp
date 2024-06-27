#include "titlewindow.h"
#include "ui_titlewindow.h"
#include <QPixmap>
#include <QDebug>
static int score1=0;
static int score2=0;
TitleWindow::TitleWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TitleWindow)
{
    ui->setupUi(this);

    // Styling the labels of players' names
    ui->player1label->setFont(QFont("Liberation Serif", 14, QFont::Normal));
    ui->player1label->setStyleSheet("QLabel { color: blue; }");
    ui->player2label->setFont(QFont("Liberation Serif", 14, QFont::Normal));
    ui->player2label->setStyleSheet("QLabel { color: blue; }");

    connect(ui->tictactoe, SIGNAL(changeplayer()), this, SLOT(Boldcurrentplayername()));
    Boldcurrentplayername();

    QPixmap pixmap("C:/Users/pc/Documents/TicTacToeProject/images/icon.png");
    if (pixmap.isNull()) {
        qDebug() << "Failed to load image";
    } else {
        int maxWidth = 200;
        int maxHeight = 200;
        QPixmap scaledPixmap = pixmap.scaled(maxWidth, maxHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->imagelabel->setPixmap(scaledPixmap);
        ui->imagelabel->setScaledContents(false);
    }

    ui->newgameButton->setFixedWidth(200);
    ui->registerbutton->setFixedWidth(200);
    connect(ui->actionNewgame, SIGNAL(triggered()), this, SLOT(startnewgame()));
    connect(ui->actionQuitgame, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->tictactoe,SIGNAL(finishgame()),this,SLOT(determinegameOutcome()));

    connect(ui->newgameButton, SIGNAL(clicked()), this, SLOT(startnewgame()));
    connect(ui->registerbutton, SIGNAL(clicked()), this, SLOT(startnewgame()));

    configuration = GameConfiguration::getInstance();
    //connectio to start Ai mode
    connect(this,SIGNAL(startaimode()),ui->tictactoe,SLOT(setaimode()));


}

TitleWindow::~TitleWindow()
{
    delete ui;
}

// Starts a new game
void TitleWindow::startnewgame()
{
    //reset score
    score1=0;
    score2=0;
    // Reset player names
    ui->player1label->setText("");
    ui->player2label->setText("");
    //clear configurations fields
    configuration->setplayer1name("");
    configuration->setplayer2name("");
    //reset ai configuration
    configuration->resetsomeconfig();
    //reset to two player
    ui->tictactoe->setTwoplayermode();

    if (configuration->exec() == QDialog::Rejected) {
        return;
    }
    //check ai
    if (configuration->getplayer2name()== Data::ainame)
    {
        ui->tictactoe->resetcontainers();
        emit startaimode();
    }
    ui->player1label->setText(configuration->getplayer1name());
    ui->player2label->setText(configuration->getplayer2name());
    //Mode mode = configuration->getMode();

    // Adjust tictactoe widget size
    ui->tictactoe->setFixedHeight(120 * (3 + 1));
    ui->tictactoe->setFixedWidth(120 * (3 + 1));

    // Hide game title
    ui->gametitle->setVisible(false);
    ui->imagelabel->setVisible(false);
    ui->newgameButton->setVisible(false);

    // Start game
    ui->tictactoe->restartgame();

    // Enable board
    ui->tictactoe->setEnabled(true);

    // Position player labels
    ui->player1label->move(ui->centralwidget->width() / 2 - ui->player1label->width() / 2, 10);
    ui->player2label->move(ui->centralwidget->width() / 2 - ui->player2label->width() / 2, ui->centralwidget->height() - ui->player2label->height() - 10);
}
/**
 * @brief TitleWindow::Boldcurrentplayername
 * current player highlighting
 */
void TitleWindow::Boldcurrentplayername()
{
    QFont playerfont = ui-> player1label->font();
    //player 1 turn
    playerfont.setBold(ui->tictactoe->getplayer()==Players::Player1);
    ui->player1label->setFont(playerfont);
    //player 2 turn
    playerfont.setBold(ui->tictactoe->getplayer()==Players::Player2);
    ui->player2label->setFont(playerfont);
}

void TitleWindow::determinegameOutcome()
{
    Winner winner = ui->tictactoe->getwinner();

    QString numberstring1=QString::number(score1);
    QString numberstring2=QString::number(score2);
    // Debugging statements
    qDebug() << "Determining game outcome...";
    qDebug() << "Winner: " << (winner == Winner::player1 ? "Player 1" : (winner == Winner::player2 ? "Player 2" : (winner == Winner::Draw ? "Draw" : "Unknown")));
    QString scoremessage1="Score: ";
    QString scoremessage2="Score: ";
    if (winner == Winner::player1)
    {
        score1=score1+1;
        numberstring1=QString::number(score1);
        QString message = "The winner is " + ui->player1label->text();
        scoremessage1=scoremessage1+ numberstring1;
        scoremessage2=scoremessage2+ numberstring2;

        ui->player1score->setText(scoremessage1);
        ui->player2score->setText(scoremessage2);
        ui->tictactoe->setoutcomemessage(message);

        // Debugging statement
        qDebug() << "Outcome message set to:" << message;
    }
    else if (winner == Winner::player2)
    {
        score2=score2+1;
        numberstring2=QString::number(score2);
        QString message = "The winner is " + ui->player2label->text();
        scoremessage1=scoremessage1+ numberstring1;
        scoremessage2=scoremessage2+ numberstring2;
        ui->player1score->setText(scoremessage1);
        ui->player2score->setText(scoremessage2);
        ui->tictactoe->setoutcomemessage(message);

        // Debugging statement
        qDebug() << "Outcome message set to:" << message;
    }
    else if (winner == Winner::Draw)
    {
        scoremessage1=scoremessage1+ numberstring1;
        scoremessage2=scoremessage2+ numberstring2;
        ui->player1score->setText(scoremessage1);
        ui->player2score->setText(scoremessage2);

        QString message = "Draw game";
        ui->tictactoe->setoutcomemessage(message);

        // Debugging statement
        qDebug() << "Outcome message set to:" << message;
    }
    else
    {
        // Handle unexpected cases
        QString message = "Unknown outcome";
        ui->tictactoe->setoutcomemessage(message);

        // Debugging statement
        qDebug() << "Outcome message set to:" << message;
    }
}



