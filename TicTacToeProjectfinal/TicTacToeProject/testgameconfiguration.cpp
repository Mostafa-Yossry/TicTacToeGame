#include <QtTest/QtTest>
#include "testgameconfiguration.h"
void IntegrationTest::initTestCase()
{
    // This method is called before the first test function is executed.
    gameConfig = GameConfiguration::getInstance();
    sessionManager = &SessionManager::instance();
    widget = new TicTacToeWidget();
}

void IntegrationTest::cleanupTestCase()
{
    // This method is called after the last test function is executed.
    delete widget;
}

void IntegrationTest::testFullGameFlow()
{
    // Simulate a user login
    QString username = "testUser";
    sessionManager->login(username);
    QCOMPARE(sessionManager->getCurrentUser(), username);

    // Set player names
    gameConfig->setplayer1name("Player1");
    gameConfig->setplayer2name("Player2");
    QCOMPARE(gameConfig->getplayer1name(), QString("Player1"));
    QCOMPARE(gameConfig->getplayer2name(), QString("Player2"));

    // Simulate setting game mode
    QMetaObject::invokeMethod(gameConfig, "on_twoplayermode_clicked", Qt::DirectConnection);
    // QCOMPARE(gameConfig->getMode(), Mode::twoplayer);

    // Test game play scenario
    widget->createBoard();
    widget->handleclicksonboard(0);
    widget->handleclicksonboard(1);
    widget->handleclicksonboard(3);
    widget->handleclicksonboard(4);
    widget->handleclicksonboard(6);

    QVERIFY(widget->getwinner() == Winner::player1);

    // Reset the game
    widget->resetBoard();
    for (int i = 0; i < MetaData::BOARDSIZE; ++i) {
        QVERIFY(widget->board.at(i)->text() == MetaData::space);
    }

    // Test user logout
    sessionManager->logout();
    QCOMPARE(sessionManager->getCurrentUser(), QString(""));
}

void TestTicTacToeWidget::initTestCase()
{
    // This method is called before the first test function is executed.
}

void TestTicTacToeWidget::cleanupTestCase()
{
    // This method is called after the last test function is executed.
}

void TestTicTacToeWidget::init()
{
    // This method is called before each test function is executed.
    widget = new TicTacToeWidget();
}

void TestTicTacToeWidget::cleanup()
{
    // This method is called after each test function is executed.
    delete widget;
}



void TestTicTacToeWidget::testDetermineWinner()
{
    // Test determine winner logic
    widget->createBoard();
    widget->handleclicksonboard(0);
    widget->handleclicksonboard(1);
    widget->handleclicksonboard(3);
    widget->handleclicksonboard(4);
    widget->handleclicksonboard(6);

    QVERIFY(widget->getwinner() == Winner::player1);
}

void TestTicTacToeWidget::testHandleClicksOnBoard()
{
    // Test handling clicks on the board
    widget->createBoard();
    widget->handleclicksonboard(0);
    QVERIFY(widget->board.at(0)->text() == "X");
    widget->handleclicksonboard(1);
    QVERIFY(widget->board.at(1)->text() == "O");
}

void TestTicTacToeWidget::testResetBoard()
{
    // Test resetting the board
    widget->createBoard();
    widget->handleclicksonboard(0);
    widget->resetBoard();
    for (int i = 0; i < MetaData::BOARDSIZE; ++i) {
        QVERIFY(widget->board.at(i)->text() == MetaData::space);
    }
}




void TestSessionManager::testLogin() {
    SessionManager &manager = SessionManager::instance();
    QString username = "testUser";
    manager.login(username);
    QCOMPARE(manager.getCurrentUser(), username);
}

void TestSessionManager::testLogout() {
    SessionManager &manager = SessionManager::instance();
    manager.logout();
    QCOMPARE(manager.getCurrentUser(), QString(""));
}

void TestSessionManager::testGetCurrentUser() {
    SessionManager &manager = SessionManager::instance();
    QString username = "anotherTestUser";
    manager.login(username);
    QCOMPARE(manager.getCurrentUser(), username);
    manager.logout();
    QCOMPARE(manager.getCurrentUser(), QString(""));
}

void TestGameConfiguration::testSingleton()
{
    GameConfiguration *instance1 = GameConfiguration::getInstance();
    GameConfiguration *instance2 = GameConfiguration::getInstance();
    QVERIFY(instance1 == instance2); // Ensure singleton property
}

void TestGameConfiguration::testSetPlayer1Name()
{
    GameConfiguration *gameConfig = GameConfiguration::getInstance();
    gameConfig->setplayer1name("Player1");
    QCOMPARE(gameConfig->getplayer1name(), QString("Player1")); // Verify player 1 name is set correctly
}

void TestGameConfiguration::testSetPlayer2Name()
{
    GameConfiguration *gameConfig = GameConfiguration::getInstance();
    gameConfig->setplayer2name("Player2");
    QCOMPARE(gameConfig->getplayer2name(), QString("Player2")); // Verify player 2 name is set correctly
}

void TestGameConfiguration::testGetPlayer1Name()
{
    GameConfiguration *gameConfig = GameConfiguration::getInstance();
    gameConfig->setplayer1name("Player1");
    QCOMPARE(gameConfig->getplayer1name(), QString("Player1")); // Verify getting player 1 name
}

void TestGameConfiguration::testGetPlayer2Name()
{
    GameConfiguration *gameConfig = GameConfiguration::getInstance();
    gameConfig->setplayer2name("Player2");
    QCOMPARE(gameConfig->getplayer2name(), QString("Player2")); // Verify getting player 2 name
}





//QTEST_MAIN(TestGameConfiguration)

