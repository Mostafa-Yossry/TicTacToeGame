#ifndef TESTGAMECONFIGURATION_H
#define TESTGAMECONFIGURATION_H

#include <QtTest/QtTest>
#include "gameconfiguration.h"
#include "sessionmanager.h"
#include "tictactoewidget.h"
class IntegrationTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testFullGameFlow();

private:
    TicTacToeWidget *widget;
    GameConfiguration *gameConfig;
    SessionManager *sessionManager;
};
class TestTicTacToeWidget : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();  // Called before the first test function is executed.
    void cleanupTestCase();  // Called after the last test function is executed.
    void init();  // Called before each test function is executed.
    void cleanup();  // Called after each test function is executed.
    void testInitialState();
    void testDetermineWinner();
    void testHandleClicksOnBoard();
    void testResetBoard();
    void testAiMoveSelection();

private:
    TicTacToeWidget* widget;
};

class TestSessionManager : public QObject
{
    Q_OBJECT

private slots:
    void testLogin();
    void testLogout();
    void testGetCurrentUser();
};
class TestGameConfiguration : public QObject
{
    Q_OBJECT

private slots:
    void testSingleton();
    void testSetPlayer1Name();
    void testSetPlayer2Name();
    void testGetPlayer1Name();
    void testGetPlayer2Name();

};

#endif // TESTGAMECONFIGURATION_H

