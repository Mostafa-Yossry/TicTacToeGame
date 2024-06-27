/********************************************************************************
** Form generated from reading UI file 'titlewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEWINDOW_H
#define UI_TITLEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "tictactoewidget.h"

QT_BEGIN_NAMESPACE

class Ui_TitleWindow {
 public:
  QAction *actionNewgame;
  QAction *actionQuitgame;
  QWidget *centralwidget;
  QVBoxLayout *verticalLayout;
  QLabel *player1label;
  QLabel *player1score;
  QLabel *gametitle;
  QLabel *imagelabel;
  QPushButton *newgameButton;
  QPushButton *registerbutton;
  TicTacToeWidget *tictactoe;
  QLabel *player2label;
  QLabel *player2score;
  QMenuBar *menubar;
  QMenu *menu_File;
  QStatusBar *statusbar;
  QToolBar *toolBar;

  void setupUi(QMainWindow *TitleWindow) {
    if (TitleWindow->objectName().isEmpty())
      TitleWindow->setObjectName("TitleWindow");
    TitleWindow->resize(800, 509);
    actionNewgame = new QAction(TitleWindow);
    actionNewgame->setObjectName("actionNewgame");
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/images/icons8-new-48.png"), QSize(),
                 QIcon::Normal, QIcon::On);
    actionNewgame->setIcon(icon);
    actionNewgame->setMenuRole(QAction::NoRole);
    actionQuitgame = new QAction(TitleWindow);
    actionQuitgame->setObjectName("actionQuitgame");
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/images/icons8-close-window-48.png"),
                  QSize(), QIcon::Normal, QIcon::On);
    actionQuitgame->setIcon(icon1);
    actionQuitgame->setMenuRole(QAction::NoRole);
    centralwidget = new QWidget(TitleWindow);
    centralwidget->setObjectName("centralwidget");
    verticalLayout = new QVBoxLayout(centralwidget);
    verticalLayout->setObjectName("verticalLayout");
    player1label = new QLabel(centralwidget);
    player1label->setObjectName("player1label");

    verticalLayout->addWidget(player1label, 0,
                              Qt::AlignHCenter | Qt::AlignVCenter);

    player1score = new QLabel(centralwidget);
    player1score->setObjectName("player1score");

    verticalLayout->addWidget(player1score);

    gametitle = new QLabel(centralwidget);
    gametitle->setObjectName("gametitle");
    gametitle->setStyleSheet(
        QString::fromUtf8("font: 32pt \"Arial\";\n"
                          "color: rgb(0, 0, 0);"));

    verticalLayout->addWidget(gametitle, 0,
                              Qt::AlignHCenter | Qt::AlignVCenter);

    imagelabel = new QLabel(centralwidget);
    imagelabel->setObjectName("imagelabel");
    imagelabel->setPixmap(QPixmap(QString::fromUtf8("images/icon.ico")));

    verticalLayout->addWidget(imagelabel, 0, Qt::AlignHCenter | Qt::AlignTop);

    newgameButton = new QPushButton(centralwidget);
    newgameButton->setObjectName("newgameButton");

    verticalLayout->addWidget(newgameButton, 0,
                              Qt::AlignHCenter | Qt::AlignVCenter);

    registerbutton = new QPushButton(centralwidget);
    registerbutton->setObjectName("registerbutton");

    verticalLayout->addWidget(registerbutton, 0, Qt::AlignHCenter);

    tictactoe = new TicTacToeWidget(centralwidget);
    tictactoe->setObjectName("tictactoe");

    verticalLayout->addWidget(tictactoe, 0,
                              Qt::AlignHCenter | Qt::AlignVCenter);

    player2label = new QLabel(centralwidget);
    player2label->setObjectName("player2label");

    verticalLayout->addWidget(player2label, 0,
                              Qt::AlignHCenter | Qt::AlignVCenter);

    player2score = new QLabel(centralwidget);
    player2score->setObjectName("player2score");

    verticalLayout->addWidget(player2score);

    TitleWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(TitleWindow);
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 800, 17));
    menu_File = new QMenu(menubar);
    menu_File->setObjectName("menu_File");
    TitleWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(TitleWindow);
    statusbar->setObjectName("statusbar");
    TitleWindow->setStatusBar(statusbar);
    toolBar = new QToolBar(TitleWindow);
    toolBar->setObjectName("toolBar");
    TitleWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

    menubar->addAction(menu_File->menuAction());
    menu_File->addAction(actionNewgame);
    menu_File->addAction(actionQuitgame);
    toolBar->addAction(actionNewgame);
    toolBar->addAction(actionQuitgame);

    retranslateUi(TitleWindow);

    QMetaObject::connectSlotsByName(TitleWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *TitleWindow) {
    TitleWindow->setWindowTitle(
        QCoreApplication::translate("TitleWindow", "MainWindow", nullptr));
    actionNewgame->setText(
        QCoreApplication::translate("TitleWindow", "Newgame", nullptr));
#if QT_CONFIG(tooltip)
    actionNewgame->setToolTip(
        QCoreApplication::translate("TitleWindow", "New Game", nullptr));
#endif  // QT_CONFIG(tooltip)
    actionQuitgame->setText(
        QCoreApplication::translate("TitleWindow", "QuitGame", nullptr));
#if QT_CONFIG(tooltip)
    actionQuitgame->setToolTip(
        QCoreApplication::translate("TitleWindow", "Quit Game", nullptr));
#endif  // QT_CONFIG(tooltip)
    player1label->setText(QString());
    player1score->setText(QString());
    gametitle->setText(
        QCoreApplication::translate("TitleWindow", "Tic-Tac-Toe", nullptr));
    imagelabel->setText(QString());
    newgameButton->setText(
        QCoreApplication::translate("TitleWindow", "New", nullptr));
    registerbutton->setText(
        QCoreApplication::translate("TitleWindow", "Register", nullptr));
    player2label->setText(QString());
    player2score->setText(QString());
    menu_File->setTitle(
        QCoreApplication::translate("TitleWindow", "&File", nullptr));
    toolBar->setWindowTitle(
        QCoreApplication::translate("TitleWindow", "toolBar", nullptr));
  }  // retranslateUi
};

namespace Ui {
class TitleWindow : public Ui_TitleWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_TITLEWINDOW_H
