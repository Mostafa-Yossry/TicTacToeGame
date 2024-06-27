/********************************************************************************
** Form generated from reading UI file 'tictactoewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICTACTOEWIDGET_H
#define UI_TICTACTOEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TicTacToeWidget {
 public:
  void setupUi(QWidget *TicTacToeWidget) {
    if (TicTacToeWidget->objectName().isEmpty())
      TicTacToeWidget->setObjectName("TicTacToeWidget");
    TicTacToeWidget->resize(800, 600);

    retranslateUi(TicTacToeWidget);

    QMetaObject::connectSlotsByName(TicTacToeWidget);
  }  // setupUi

  void retranslateUi(QWidget *TicTacToeWidget) {
    TicTacToeWidget->setWindowTitle(QCoreApplication::translate(
        "TicTacToeWidget", "TicTacToeWidget", nullptr));
  }  // retranslateUi
};

namespace Ui {
class TicTacToeWidget : public Ui_TicTacToeWidget {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_TICTACTOEWIDGET_H
