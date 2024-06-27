/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ainWindow {
 public:
  QWidget *centralwidget;
  QLabel *player1label;
  QLabel *player2label;
  QLabel *label;
  QLabel *label_2;
  QMenuBar *menubar;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *ainWindow) {
    if (ainWindow->objectName().isEmpty())
      ainWindow->setObjectName("ainWindow");
    ainWindow->resize(800, 600);
    centralwidget = new QWidget(ainWindow);
    centralwidget->setObjectName("centralwidget");
    player1label = new QLabel(centralwidget);
    player1label->setObjectName("player1label");
    player1label->setGeometry(QRect(60, 300, 161, 31));
    player1label->setAlignment(Qt::AlignCenter);
    player2label = new QLabel(centralwidget);
    player2label->setObjectName("player2label");
    player2label->setGeometry(QRect(550, 300, 161, 31));
    player2label->setAlignment(Qt::AlignCenter);
    label = new QLabel(centralwidget);
    label->setObjectName("label");
    label->setGeometry(QRect(140, 20, 521, 51));
    label->setStyleSheet(
        QString::fromUtf8("font: 700 31pt \"Arial\";\n"
                          "color: rgb(0, 0, 0);\n"
                          ""));
    label->setAlignment(Qt::AlignCenter);
    label_2 = new QLabel(centralwidget);
    label_2->setObjectName("label_2");
    label_2->setGeometry(QRect(260, 80, 251, 231));
    label_2->setMaximumSize(QSize(16777215, 241));
    label_2->setPixmap(QPixmap(QString::fromUtf8("images/icon.ico")));
    ainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(ainWindow);
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 800, 21));
    ainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(ainWindow);
    statusbar->setObjectName("statusbar");
    ainWindow->setStatusBar(statusbar);

    retranslateUi(ainWindow);

    QMetaObject::connectSlotsByName(ainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *ainWindow) {
    ainWindow->setWindowTitle(
        QCoreApplication::translate("ainWindow", "MainWindow", nullptr));
    player1label->setText(
        QCoreApplication::translate("ainWindow", "playere 1", nullptr));
    player2label->setText(
        QCoreApplication::translate("ainWindow", "player 2", nullptr));
    label->setText(
        QCoreApplication::translate("ainWindow", "TIC-TAC-TOE  ", nullptr));
    label_2->setText(QString());
  }  // retranslateUi
};

namespace Ui {
class ainWindow : public Ui_ainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
