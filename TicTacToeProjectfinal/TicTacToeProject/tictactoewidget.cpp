#include "tictactoewidget.h"
#include "ui_tictactoewidget.h"
#include <limits>
#include <algorithm>
#include<QDebug>
#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QSignalMapper>
#include <QTimer>
#include <QLabel>
#include <stdlib.h>
#include <time.h>
Winner winner = Winner::NoWinnerYet ;
TicTacToeWidget::TicTacToeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TicTacToeWidget)
{
    ui->setupUi(this);
    // Set fixed size for the widget
    this->setFixedSize(500, 500); // Adjust this size as needed
    // Board creation upon object creation in main
    //createBoard();
    player = Players::Player1;
    emit changeplayer();
    mode = Modedata::Twoplayermode;//default
    //connection of ai moves to handleclicks in board
    connect(this,SIGNAL(sendaimoves(int)),this,SLOT(handleclicksonboard(int)));
    connect(this,SIGNAL(triggerAi()),this,SLOT(triggeraimodecalculation()));
    // a connection between the signal to start ai move calculation
    connect(this, SIGNAL(startaimovecalculation()), this, SLOT(calculateaimove()));

}

/**
 * @brief TicTacToeWidget::resetBoard
 * function resets the board after every game session
 */
void TicTacToeWidget::resetBoard()
{
    for (int i =0; i< MetaData::BOARDSIZE; i++){
        board.at(i)->setText(MetaData::space);
    }
}
/**
 * @brief TicTacToeWidget::createcurrentplayer
 * @param p
 * Function creates a new player
 */
void TicTacToeWidget::currentplayer(Players p)
{
    player =p;
    if (mode == Modedata::Aimode)
    {
        emit triggerAi();
    }
}
/**
 * @brief TicTacToeWidget::getplayer
 * @return
 * Function returns a player
 */
Players TicTacToeWidget::getplayer() const
{
    return player;
}

Winner TicTacToeWidget::getwinner()
{
    qDebug() << "getwinner() called, winner is:"
             << (winner == Winner::player1 ? "Player 1"
                                           : (winner == Winner::player2 ? "Player 2"
                                                                        : (winner == Winner::Draw ? "Draw"
                                                                                                  : "No Winner Yet")));
    return winner;
}




void TicTacToeWidget::setoutcomemessage(const QString &msg)
{
    outcome = msg;
    qDebug() << "setoutcomemessage() called, outcome message set to:" << msg;
}
/**
 * @brief TicTacToeWidget::resetcontainers
 * reset moves in ai mode

 */
void TicTacToeWidget::resetcontainers()
{
    player1Moves.clear();
    playerAiMoves.clear();
}
/**
 * @brief TicTacToeWidget::createBoard
 * A function which creates the game board
 */
void TicTacToeWidget::createBoard()
{
    // Creating of grid object
    QGridLayout* grid = new QGridLayout(this);

    // Set the spacing and margins to 0 to eliminate gaps between buttons
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    // Creation of a signal mapper
    QSignalMapper* mapper = new QSignalMapper(this);

    for (int row = 0; row < MetaData::ROWS; row++) {
        for (int column = 0; column < MetaData::COLUMNS; column++) {
            // Creating buttons
            QPushButton* button = new QPushButton(this);
            // Button set up
            button->setText(MetaData::space);
            // Set fixed size for buttons
            button->setFixedSize(150, 100); // Adjust this size as needed
            // Add button to the grid
            grid->addWidget(button, row, column);
            // Mapping every button with their board index
            mapper->setMapping(button, board.size());
            // Connecting button click event to a signal
            // Connection of the click on a button to a slot of the QSignalMapper
            // which is going to emit a mappedInt signal as a result, this signal
            // contains the id of button
            connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
            // The map signal emitted is then connected to a slot handleclicksonboard and the
            // index is passed to it.
            connect(mapper, SIGNAL(mappedInt(int)), this, SLOT(handleclicksonboard(int)));
            // Add the buttons to the board
            board.append(button);
        }
    }

    // Set the layout on the widget
    setLayout(grid);
}
/**
 * @brief TicTacToeWidget::determine winner
 * @return
 * function returns winner of game
 */
Winner TicTacToeWidget::determinewinner(const QString &symbol, int buttonindex)
{
    // position of button on the board it's rownumber and it's column number
    int rownumber = buttonindex / MetaData::COLUMNS;
    int columnnumber = buttonindex % MetaData::COLUMNS;
    int counter = 0;

    // Check horizontal
    counter = horizontalcheck(symbol, rownumber, columnnumber);
    if (counter == MetaData::ROWS)
    {
        if (symbol == "X")
        {
            return winner=Winner::player1;
        }
        else if (symbol == "O")
        {
            return winner = Winner::player2;
        }
    }

    // Check vertical
    counter = verticalcheck(symbol, rownumber, columnnumber);
    if (counter == MetaData::ROWS)
    {
        if (symbol == "X")
        {
            return winner= Winner::player1;
        }
        else if (symbol == "O")
        {
            return winner= Winner::player2;
        }
    }

    // Check diagonal (top-left to bottom-right)
    if (buttonindex % (MetaData::ROWS +1)==0)
    {
    counter = backwardslashdiagonalcheck(symbol, rownumber, columnnumber);
    if (counter == MetaData::ROWS)
    {
        if (symbol == "X")
        {
            return winner=Winner::player1;
        }
        else if (symbol == "O")
        {
            return winner =Winner::player2;
        }
    }
    }

    // Check forward slash diagonal (bottom-left to top-right)
    if (buttonindex % (MetaData::ROWS -1)==0)
    {
    counter = forwardslashdiagonalcheck(symbol, rownumber, columnnumber);
    if (counter == MetaData::ROWS)
    {
        if (symbol == "X")
        {

            return winner = Winner::player1;
        }
        else if (symbol == "O")
        {
            return winner =Winner::player2;
        }
    }
    }
    // check for draw
    for ( int i =0; i < MetaData::BOARDSIZE ; i++)
    {
        if ( board.at(i)-> text()==" ")
        {
            return winner = Winner::NoWinnerYet;
        }
    }
    //return Winner::Draw;
    for ( int i = 0 ; i < MetaData::BOARDSIZE; i++)
    {
        if (board.at(i)->text()==" ")
        {return winner = Winner::NoWinnerYet;}
    }
    return winner=Winner::Draw;
}

int TicTacToeWidget::horizontalcheck(const QString &symbol, int rownumber, int columnnumber)
{
    // horizontal forward check
    int counter = 1; // Start from 1 to count the current position
    int newcolumn = columnnumber + 1;

    while (newcolumn < MetaData::COLUMNS)
    {
        int newposition = rownumber * MetaData::COLUMNS + newcolumn;
        QPushButton *button = board.at(newposition);
        if (button->text() != symbol)
        {
            break;
        }
        counter++;
        newcolumn++;
    }

    // horizontal backward check
    newcolumn = columnnumber - 1;
    while (newcolumn >= 0)
    {
        int newposition = rownumber * MetaData::COLUMNS + newcolumn;
        QPushButton *button = board.at(newposition);
        if (button->text() != symbol)
        {
            break;
        }
        counter++;
        newcolumn--;
    }

    return counter;
}
int TicTacToeWidget::verticalcheck(const QString &symbol, int rownumber, int columnnumber)
{
    int counter = 1; // Start from 1 to count the current position
    int newrow = rownumber - 1;

    // vertical check upward
    while (newrow >= 0)
    {
        int newpositionindex = newrow * MetaData::COLUMNS + columnnumber;
        QPushButton *button = board.at(newpositionindex);
        if (button->text() != symbol)
        {
            break;
        }
        counter++;
        newrow--;
    }

    // downward check
    newrow = rownumber + 1;
    while (newrow < MetaData::ROWS)
    {
        int newpositionindex = newrow * MetaData::COLUMNS + columnnumber;
        QPushButton *button = board.at(newpositionindex);
        if (button->text() != symbol)
        {
            break;
        }
        counter++;
        newrow++;
    }

    return counter;
}
int TicTacToeWidget::backwardslashdiagonalcheck(const QString &symbol, int rownumber, int columnnumber)
{
    int counter = 1; // Start from 1 to count the current position
    int newrow = rownumber - 1;
    int newcolumn = columnnumber - 1;

    // Diagonal check (top-left to bottom-right)
    while (newrow >= 0 && newcolumn >= 0)
    {
        int newpositionindex = newrow * MetaData::COLUMNS + newcolumn;
        QPushButton *button = board.at(newpositionindex);
        if (button->text() != symbol)
        {
            break;
        }
        counter++;
        newrow--;
        newcolumn--;
    }

    newrow = rownumber + 1;
    newcolumn = columnnumber + 1;
    while (newrow < MetaData::ROWS && newcolumn < MetaData::COLUMNS)
    {
        int newpositionindex = newrow * MetaData::COLUMNS + newcolumn;
        QPushButton *button = board.at(newpositionindex);
        if (button->text() != symbol)
        {
            break;
        }
        counter++;
        newrow++;
        newcolumn++;
    }

    return counter;
}
int TicTacToeWidget::forwardslashdiagonalcheck(const QString &symbol, int rownumber, int columnnumber)
{
    int counter = 1; // Start from 1 to count the current position
    int newrow = rownumber + 1;
    int newcolumn = columnnumber - 1;

    // Forward slash diagonal check (bottom-left to top-right)
    while (newrow < MetaData::ROWS && newcolumn >= 0)
    {
        int newpositionindex = newrow * MetaData::COLUMNS + newcolumn;
        QPushButton *button = board.at(newpositionindex);
        if (button->text() != symbol)
        {
            break;
        }
        counter++;
        newrow++;
        newcolumn--;
    }

    newrow = rownumber - 1;
    newcolumn = columnnumber + 1;
    while (newrow >= 0 && newcolumn < MetaData::COLUMNS)
    {
        int newpositionindex = newrow * MetaData::COLUMNS + newcolumn;
        QPushButton *button = board.at(newpositionindex);
        if (button->text() != symbol)
        {
            break;
        }
        counter++;
        newrow--;
        newcolumn++;
    }

    return counter;
}

TicTacToeWidget::~TicTacToeWidget()
{
    delete ui;
}
/**
 * @brief TicTacToeWidget::handleclicksonboard
 * a slot to handle clicks on the board
 */
void TicTacToeWidget::handleclicksonboard(int buttonindex)
{
    //the button which was clicked on
    QPushButton* button = board.at(buttonindex);
    button->setFont(QFont("Tahoma",12, QFont::Bold));
    // Case of invalid index
    if (buttonindex < 0 || buttonindex>=board.size())
    {
        return;
    }

    //Case of invalid move (button already contains text)
    if (button->text()!=MetaData::space){
        return;
    }
    QString symbol;
    // Write text on button according to the player
    if(player == Players::Player1)
    {
        player1lastmove= buttonindex;
        symbol = "X";
        button->setText(symbol);
        //button->setStyleSheet(QString("QPushButton{color:") + MetaData::player1colour +";background: lightgreen;}");
        //button->setDisabled(true);
    }
    else if (player == Players::Player2)
    {
        symbol = "O";
        button->setText(symbol);
        //button->setStyleSheet(QString("QPushButton{color:") + MetaData::player2colour +";background: lightyellow}");
        //button->setDisabled(true);
    }
    Winner winner = determinewinner(symbol,buttonindex);
    if(winner == Winner::NoWinnerYet)
    {
        if(player == Players::Player1)
        {
            currentplayer(Players::Player2);
            emit changeplayer();
        }
        else if (player == Players::Player2)
        {
            currentplayer(Players::Player1);
            emit changeplayer();
        }

    }
    else
    {
        //disable the board
        this -> setDisabled(true);
        QTimer::singleShot(MetaData::freezetime,this,SIGNAL(finishgame()));
        connect(this, SIGNAL(finishgame()),this,SLOT(handleendofgame()));
    }
}
/**
 * @brief TicTacToeWidget::handleendofgame
 * function handles the end of the game
 */

void TicTacToeWidget::handleendofgame()
{
    // Clear the TicTacToe window
    QLayout* layout = this->layout();
    QLayoutItem* layoutitem;
    while(layout != nullptr && (layoutitem = layout->takeAt(0)) != nullptr)
    {
        delete layoutitem->widget();
        delete layoutitem;
    }
    delete layout;

    board.clear();

    // Create a new window to display the outcome
    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->setAlignment(Qt::AlignCenter);

    QLabel* restartlabel = new QLabel(this);
    QPushButton* restartbutton = new QPushButton("Play again", this);
    QString restartlabelcolour;
    QString restartbuttoncolour;
    if (winner == Winner::player1)
    {
        restartlabelcolour = QString("QPushButton{color:") + MetaData::player1colour + ";}";
        restartbuttoncolour = QString("QPushButton{color:") + MetaData::player1colour + ";}";
    }
    else if (winner == Winner::player2)
    {
        restartlabelcolour = QString("QPushButton{color:") + MetaData::player2colour + ";}";
        restartbuttoncolour = QString("QPushButton{color:") + MetaData::player2colour + ";}";
    }
    else if (winner == Winner::Draw)
    {
        restartlabelcolour = QString("QPushButton{color:") + MetaData::drawcolour + ";}";
        restartbuttoncolour = QString("QPushButton{color:") + MetaData::drawcolour + ";}";
    }

    restartbutton->setMinimumHeight(40);
    restartbutton->setMinimumWidth(100);
    restartbutton->setFont(QFont("Liberation Serif", 14, QFont::Bold));
    restartbutton->setStyleSheet(restartbuttoncolour);
    restartlabel->setFont(QFont("Liberation Serif", 14, QFont::Bold));
    restartlabel->setStyleSheet(restartlabelcolour);
    restartlabel->setText(outcome);

    this->setMaximumWidth(MetaData::endofgamewidth);

    vlayout->addWidget(restartlabel);
    vlayout->addWidget(restartbutton);

    this->setEnabled(true);


    connect(restartbutton, SIGNAL(clicked()), this, SLOT(restartgame()));
}

void TicTacToeWidget::triggeraimodecalculation()
{
    if(player == Players::Player2)
    {
        this->setDisabled(true);
        QTimer::singleShot(MetaData::aidelay, this, SIGNAL(startaimovecalculation()));
    }
    else if (player == Players::Player1)
    {
        this->setEnabled(true);
    }
}
/**
 * @brief TicTacToeWidget::calculateaimove
 * function  calculates move of ai
 **
    //store player1 move
    player1Moves.push_back(player1lastmove);
    // generate random number
    srand(time(NULL));
    int randomnumber = rand()%(MetaData::ROWS*MetaData::COLUMNS);
    //ensure a free spot
    while(randomnumber>= MetaData::ROWS*MetaData::COLUMNS || player1Moves.contains(randomnumber)
    || playerAiMoves.contains(randomnumber))
    {
        randomnumber = rand()%(MetaData::ROWS*MetaData::COLUMNS);
    }
    playerAiMoves.push_back(randomnumber);
    transmitaimove(randomnumber);
 */
// Function to calculate the best move for the AI using the minimax algorithm
void TicTacToeWidget::calculateaimove()
{
    int bestMove = -1; // Initialize the best move as -1 (invalid move)
    int bestValue = std::numeric_limits<int>::min(); // Initialize the best value as the minimum possible integer

    // Iterate over all possible moves on the board
    for (int i = 0; i < MetaData::BOARDSIZE; i++) {
        // If the current cell is empty (available for a move)
        if (board.at(i)->text() == MetaData::space) {
            board.at(i)->setText(MetaData::AI); // Make the move (AI uses 'O')
            // Call minimax to evaluate the move and get its value
            int moveValue = minimax(0, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
            board.at(i)->setText(MetaData::space); // Undo the move

            // If the value of the current move is better than the best value
            if (moveValue > bestValue) {
                bestMove = i; // Update the best move
                bestValue = moveValue; // Update the best value
            }
        }
    }

    // If a valid best move is found, emit the signal to make the move
    if (bestMove != -1) {
        emit sendaimoves(bestMove);
    }
}

// Minimax function with alpha-beta pruning
int TicTacToeWidget::minimax(int depth, bool isMax, int alpha, int beta)
{
    int score = evaluate(); // Evaluate the current board state

    // If the current board state is a winning state for the AI
    if (score == 10) return score - depth;
    // If the current board state is a winning state for the player
    if (score == -10) return score + depth;
    // If there are no more moves left (draw)
    if (!isMovesLeft()) return 0;

    // If it's the maximizer's turn (AI's turn)
    if (isMax) {
        int best = std::numeric_limits<int>::min(); // Initialize the best value as the minimum possible integer

        // Iterate over all possible moves on the board
        for (int i = 0; i < MetaData::BOARDSIZE; i++) {
            // If the current cell is empty (available for a move)
            if (board.at(i)->text() == MetaData::space) {
                board.at(i)->setText(MetaData::AI); // Make the move (AI uses 'O')
                // Call minimax recursively and choose the maximum value
                best = std::max(best, minimax(depth + 1, !isMax, alpha, beta));
                board.at(i)->setText(MetaData::space); // Undo the move
                alpha = std::max(alpha, best); // Update alpha

                // Alpha-beta pruning: if beta is less than or equal to alpha, break the loop
                if (beta <= alpha) break;
            }
        }
        return best; // Return the best value
    }
    // If it's the minimizer's turn (Player's turn)
    else {
        int best = std::numeric_limits<int>::max(); // Initialize the best value as the maximum possible integer

        // Iterate over all possible moves on the board
        for (int i = 0; i < MetaData::BOARDSIZE; i++) {
            // If the current cell is empty (available for a move)
            if (board.at(i)->text() == MetaData::space) {
                board.at(i)->setText(MetaData::Player1); // Make the move (Player uses 'X')
                // Call minimax recursively and choose the minimum value
                best = std::min(best, minimax(depth + 1, !isMax, alpha, beta));
                board.at(i)->setText(MetaData::space); // Undo the move
                beta = std::min(beta, best); // Update beta

                // Alpha-beta pruning: if beta is less than or equal to alpha, break the loop
                if (beta <= alpha) break;
            }
        }
        return best; // Return the best value
    }
}

// Function to evaluate the current board state and return a score
int TicTacToeWidget::evaluate()
{
    // Check rows for victory
    for (int row = 0; row < MetaData::ROWS; row++) {
        if (board.at(row * MetaData::COLUMNS)->text() == board.at(row * MetaData::COLUMNS + 1)->text() &&
            board.at(row * MetaData::COLUMNS + 1)->text() == board.at(row * MetaData::COLUMNS + 2)->text()) {
            if (board.at(row * MetaData::COLUMNS)->text() == MetaData::AI) return 10;
            else if (board.at(row * MetaData::COLUMNS)->text() == MetaData::Player1) return -10;
        }
    }

    // Check columns for victory
    for (int col = 0; col < MetaData::COLUMNS; col++) {
        if (board.at(col)->text() == board.at(MetaData::COLUMNS + col)->text() &&
            board.at(MetaData::COLUMNS + col)->text() == board.at(2 * MetaData::COLUMNS + col)->text()) {
            if (board.at(col)->text() == MetaData::AI) return 10;
            else if (board.at(col)->text() == MetaData::Player1) return -10;
        }
    }

    // Check diagonals for victory
    if (board.at(0)->text() == board.at(4)->text() && board.at(4)->text() == board.at(8)->text()) {
        if (board.at(0)->text() == MetaData::AI) return 10;
        else if (board.at(0)->text() == MetaData::Player1) return -10;
    }
    if (board.at(2)->text() == board.at(4)->text() && board.at(4)->text() == board.at(6)->text()) {
        if (board.at(2)->text() == MetaData::AI) return 10;
        else if (board.at(2)->text() == MetaData::Player1) return -10;
    }

    return 0; // If no one has won, return 0
}

// Function to check if there are any moves left on the board
bool TicTacToeWidget::isMovesLeft()
{
    for (int i = 0; i < MetaData::BOARDSIZE; i++) {
        if (board.at(i)->text() == MetaData::space) {
            return true; // If there's at least one empty cell, return true
        }
    }
    return false; // If no empty cells are left, return false
}

void TicTacToeWidget::transmitaimove(int move)
{
    emit(sendaimoves(move));
}

void TicTacToeWidget::restartgame()
{
    // Set first player to start playing
    player = Players::Player1;
    emit changeplayer();
    // Reset movements in AI mode
    if (mode == Modedata::Aimode)
    {
        resetcontainers();
    }
    // Clear the TicTacToe window
    QLayout* layout = this->layout();
    QLayoutItem* layoutitem;
    while(layout != nullptr && (layoutitem = layout->takeAt(0)) != nullptr)
    {
        delete layoutitem->widget();
        delete layoutitem;
    }
    delete layout;

    board.clear();
    // Create a new board
    createBoard();
    this->setEnabled(true);
}

/**
 * function sets the ai mode
 * @brief TicTacToeWidget::setaimode
 */
void TicTacToeWidget::setaimode()
{
    mode = Modedata::Aimode;
}

void TicTacToeWidget::setTwoplayermode()
{
    mode = Modedata::Twoplayermode;
}

