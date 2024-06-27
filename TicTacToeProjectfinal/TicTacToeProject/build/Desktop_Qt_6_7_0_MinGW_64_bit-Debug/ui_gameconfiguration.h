/********************************************************************************
** Form generated from reading UI file 'gameconfiguration.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMECONFIGURATION_H
#define UI_GAMECONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameConfiguration {
 public:
  QDialogButtonBox *buttonBox;
  QLabel *label;
  QLabel *player1label;
  QLabel *player2label;
  QLineEdit *player1line;
  QLineEdit *player2line;
  QWidget *widget;
  QVBoxLayout *verticalLayout;
  QRadioButton *twoplayermode;
  QRadioButton *AIMode;

  void setupUi(QDialog *GameConfiguration) {
    if (GameConfiguration->objectName().isEmpty())
      GameConfiguration->setObjectName("GameConfiguration");
    GameConfiguration->resize(400, 300);
    buttonBox = new QDialogButtonBox(GameConfiguration);
    buttonBox->setObjectName("buttonBox");
    buttonBox->setGeometry(QRect(220, 260, 171, 31));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel |
                                  QDialogButtonBox::Ok);
    label = new QLabel(GameConfiguration);
    label->setObjectName("label");
    label->setGeometry(QRect(110, 30, 161, 21));
    label->setStyleSheet(
        QString::fromUtf8("font: 700 20pt \"Arial\";\n"
                          "color: rgb(0, 0, 0);\n"
                          ""));
    player1label = new QLabel(GameConfiguration);
    player1label->setObjectName("player1label");
    player1label->setGeometry(QRect(40, 80, 61, 21));
    player1label->setStyleSheet(
        QString::fromUtf8("font: 700 11pt \"Arial\";\n"
                          "color: rgb(0, 0, 0);"));
    player2label = new QLabel(GameConfiguration);
    player2label->setObjectName("player2label");
    player2label->setGeometry(QRect(40, 140, 61, 21));
    player2label->setStyleSheet(
        QString::fromUtf8("font: 700 11pt \"Arial\";\n"
                          "color: rgb(0, 0, 0);"));
    player1line = new QLineEdit(GameConfiguration);
    player1line->setObjectName("player1line");
    player1line->setGeometry(QRect(120, 80, 221, 21));
    player1line->setStyleSheet(
        QString::fromUtf8("font: 10pt \"Arial\";\n"
                          "background-color: rgb(255, 255, 255);"));
    player2line = new QLineEdit(GameConfiguration);
    player2line->setObjectName("player2line");
    player2line->setGeometry(QRect(120, 140, 221, 21));
    player2line->setStyleSheet(
        QString::fromUtf8("font: 10pt \"Arial\";\n"
                          "background-color: rgb(255, 255, 255);"));
    widget = new QWidget(GameConfiguration);
    widget->setObjectName("widget");
    widget->setGeometry(QRect(10, 230, 138, 50));
    verticalLayout = new QVBoxLayout(widget);
    verticalLayout->setObjectName("verticalLayout");
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    twoplayermode = new QRadioButton(widget);
    twoplayermode->setObjectName("twoplayermode");
    twoplayermode->setStyleSheet(
        QString::fromUtf8("font: 700 10pt \"Arial\";\n"
                          "color: rgb(0, 0, 0);"));

    verticalLayout->addWidget(twoplayermode);

    AIMode = new QRadioButton(widget);
    AIMode->setObjectName("AIMode");
    AIMode->setStyleSheet(
        QString::fromUtf8("font: 12pt \"Arial\";\n"
                          "font: 700 10pt \"Arial\";\n"
                          "color: rgb(0, 0, 0);\n"
                          ""));

    verticalLayout->addWidget(AIMode);

    retranslateUi(GameConfiguration);
    QObject::connect(buttonBox, &QDialogButtonBox::accepted, GameConfiguration,
                     qOverload<>(&QDialog::accept));
    QObject::connect(buttonBox, &QDialogButtonBox::rejected, GameConfiguration,
                     qOverload<>(&QDialog::reject));
    QObject::connect(player1line, SIGNAL(textChanged(QString)),
                     GameConfiguration, SLOT(updateOKButton()));
    QObject::connect(player2line, SIGNAL(textChanged(QString)),
                     GameConfiguration, SLOT(updateOKButton()));

    QMetaObject::connectSlotsByName(GameConfiguration);
  }  // setupUi

  void retranslateUi(QDialog *GameConfiguration) {
    GameConfiguration->setWindowTitle(
        QCoreApplication::translate("GameConfiguration", "Dialog", nullptr));
    label->setText(QCoreApplication::translate("GameConfiguration",
                                               "Tic-Tac-Toe", nullptr));
    player1label->setText(
        QCoreApplication::translate("GameConfiguration", "Player 1", nullptr));
    player2label->setText(
        QCoreApplication::translate("GameConfiguration", "Player 2", nullptr));
    twoplayermode->setText(QCoreApplication::translate(
        "GameConfiguration", "Two Player mode", nullptr));
    AIMode->setText(
        QCoreApplication::translate("GameConfiguration", "AI mode", nullptr));
  }  // retranslateUi
};

namespace Ui {
class GameConfiguration : public Ui_GameConfiguration {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_GAMECONFIGURATION_H
