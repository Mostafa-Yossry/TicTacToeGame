#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>
#include <QTimer>
#include <QLabel>
#include <memory>

//MetaData
struct MetaData{
    static constexpr int ROWS = 3;
    static constexpr int COLUMNS = 3;
    static constexpr int BOARDSIZE = ROWS*COLUMNS;
    static constexpr const char* space = " ";
    static constexpr const char* player1colour = "Green";
    static constexpr const char* player2colour = "blue";
    static constexpr const char* drawcolour = "black";
    static constexpr int freezetime = 2000;
    static constexpr int endofgamewidth = 500;
    static constexpr int aidelay = 1000;
    static constexpr const char* AI = "O";
    static constexpr const char* Player1 = "X";

};

// enum to represent the Players
enum Players{
    Player1, Player2
};
// enum to represent the winner
enum Winner{
    player1,player2,Draw,NoWinnerYet
};
enum Modedata
{
    Aimode,Twoplayermode
};

QT_BEGIN_NAMESPACE
namespace Ui {
class TicTacToeWidget;
}
QT_END_NAMESPACE

class TicTacToeWidget : public QWidget
{
    Q_OBJECT

public:
    TicTacToeWidget(QWidget *parent = nullptr);
    //function resets the board
    void resetBoard();
    //Create player
    void currentplayer(Players p);
    //Get player, const to ensure function does not
    //change any member values
    Players getplayer()const;
    Winner getwinner();
    void setoutcomemessage(const QString&);
    //a function to reset the mist of moves
    void resetcontainers();
    Ui::TicTacToeWidget *ui;
    QList<QPushButton*>board;
    //function creates the board
    void createBoard();
    Players player;
    Winner winner;
    //game outcome
    QString outcome;
    // function to determine winner
    Winner determinewinner(const QString&, int);
    int horizontalcheck(const QString &,int rownumber, int columnnumber);
    int verticalcheck(const QString &,int rownumber, int columnnumber);
    int backwardslashdiagonalcheck(const QString &,int rownumber, int columnnumber);
    int forwardslashdiagonalcheck(const QString &, int rownumber, int columnnumber);
    int minimax (int, bool,int,int);
    int evaluate();
    bool isMovesLeft();
    Modedata mode;
    //store the moves of player1
    QList<int> player1Moves;
    //store the moves of AI
    QList<int> playerAiMoves;
    //store player 1 last move
    int player1lastmove;
    ~TicTacToeWidget();
signals:
    void finishgame();
    void changeplayer();
    //signal transmits ai moves
    void sendaimoves(int);
    //signal which signals ai mode
    void triggerAi();
    //signal to trigger the start of calculation
    void startaimovecalculation();
private slots:
    //Function to handle clicks on board receives
    //the index of the button
    // void handleclicksonboard(int);
    // //end of the game
    // void handleendofgame();
    // //slot to do ai move calculation
    // void triggeraimodecalculation();
    // //slot compute ai move
    // void calculateaimove();
    // //function sends the ai move
    // void transmitaimove(int);
public slots:
    //restart or start a game
    void restartgame();
    //slot to set the ai
    void setaimode();
    //reset to two player mode
    void setTwoplayermode();
    void handleclicksonboard(int);
    //end of the game
    void handleendofgame();
    //slot to do ai move calculation
    void triggeraimodecalculation();
    //slot compute ai move
    void calculateaimove();
    //function sends the ai move
    void transmitaimove(int);

private:
    // Ui::TicTacToeWidget *ui;
    // QList<QPushButton*>board;
    // //function creates the board
    // void createBoard();
    // Players player;
    // Winner winner;
    // //game outcome
    // QString outcome;
    // // function to determine winner
    // Winner determinewinner(const QString&, int);
    // int horizontalcheck(const QString &,int rownumber, int columnnumber);
    // int verticalcheck(const QString &,int rownumber, int columnnumber);
    // int backwardslashdiagonalcheck(const QString &,int rownumber, int columnnumber);
    // int forwardslashdiagonalcheck(const QString &, int rownumber, int columnnumber);
    // int minimax (int, bool,int,int);
    // int evaluate();
    // bool isMovesLeft();
    // Modedata mode;
    // //store the moves of player1
    // QList<int> player1Moves;
    // //store the moves of AI
    // QList<int> playerAiMoves;
    // //store player 1 last move
    // int player1lastmove;


};
#endif // TICTACTOEWIDGET_H
