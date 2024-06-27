#ifndef TEST_SESSIONMANAGER_H
#define TEST_SESSIONMANAGER_H

#include <QObject>
#include <QtTest/QtTest>

#include "sessionmanager.h"

class TestSessionManager : public QObject {
  Q_OBJECT

 private slots:
  void testLogin();
  void testLogout();
  void testGetCurrentUser();
};

#endif  // TEST_SESSIONMANAGER_H
