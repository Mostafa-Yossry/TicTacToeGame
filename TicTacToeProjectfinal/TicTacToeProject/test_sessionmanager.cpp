#include "test_sessionmanager.h"

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

// QTEST_MAIN(TestSessionManager)
#include "test_sessionmanager.moc"
