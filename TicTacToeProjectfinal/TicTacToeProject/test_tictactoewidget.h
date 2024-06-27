#ifndef TEST_TICTACTOEWIDGET_H
#define TEST_TICTACTOEWIDGET_H

#include <QObject>
#include <QtTest/QtTest>
#include "tictactoewidget.h"

class TestTicTacToeWidget : public QObject
{
    Q_OBJECT

private slots:
    void testInitialState();
    void testPlayerChange();
    void testResetBoard();
    void testDetermineWinner();
    void testAITrigger();
    void testMinimax();
    void testEvaluate();
    void testIsMovesLeft();
    void testHandleClick();
    void testRestartGame();
};

#endif // TEST_TICTACTOEWIDGET_H

