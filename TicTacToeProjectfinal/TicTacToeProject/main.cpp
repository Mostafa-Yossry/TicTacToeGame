#include "tictactoewidget.h"
#include"gameconfiguration.h"
#include "titlewindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <form.h>
#include <loginform.h>
#include "testgameconfiguration.h"

void createDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tic_tac_toe.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
    } else {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    QString createTable = "CREATE TABLE IF NOT EXISTS users ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "username TEXT NOT NULL UNIQUE, "
                          "password TEXT NOT NULL)";
    if (!query.exec(createTable)) {
        qDebug() << "Couldn't create the table 'users': one might already exist.";
    }
}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    createDatabase();
    TitleWindow window;
    window.show();
    Form regForm;
    regForm.show();
    LoginForm loginForm;
    loginForm.show();
    TestTicTacToeWidget test3;
    TestSessionManager test2;
    TestGameConfiguration test1;
    IntegrationTest testintegrate;

  // return QTest::qExec(&testintegrate, argc, argv);
    return a.exec();
}
