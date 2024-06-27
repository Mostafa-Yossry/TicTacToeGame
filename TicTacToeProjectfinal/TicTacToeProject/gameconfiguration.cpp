#include "gameconfiguration.h"

#include <QDebug>
#include <QPushButton>

#include "ui_gameconfiguration.h"

GameConfiguration::GameConfiguration(QWidget *parent)
    : QDialog(parent), ui(new Ui::GameConfiguration) {
  ui->setupUi(this);
  // Ensure that ok is disabled
  updateOKButton();
  // Default game mode
  ui->twoplayermode->setChecked(true);
}

GameConfiguration::~GameConfiguration() { delete ui; }

void GameConfiguration::setplayer1name(const QString &name) const {
  ui->player1line->setText(name);
}

void GameConfiguration::setplayer2name(const QString &name) const {
  ui->player2line->setText(name);
}

QString GameConfiguration::getplayer1name() const {
  return ui->player1line->text();
}

QString GameConfiguration::getplayer2name() const {
  return ui->player2line->text();
}

// Function to return the selected game mode
Mode GameConfiguration::getMode() const {
  if (ui->twoplayermode->isChecked()) {
    return twoplayer;
  } else if (ui->AIMode->isChecked()) {
    return AI;
  }
  // Default return value, if no mode is checked (this should not happen if the
  // UI is properly set up)
  return twoplayer;
}

// Initialization of the pointer to the single instance
GameConfiguration *GameConfiguration::gameconfig = nullptr;

/**
 * @brief GameConfiguration::getInstance
 * @return A function which returns the unique instance of the game
 * configuration class
 */
GameConfiguration *GameConfiguration::getInstance() {
  if (gameconfig == nullptr) {
    gameconfig = new GameConfiguration;
  }
  return gameconfig;
}
/**
 * a function which resets some game configurations
 * @brief GameConfiguration::resetsomeconfig
 */
void GameConfiguration::resetsomeconfig() {
  ui->twoplayermode->setChecked(true);
  ui->player2line->setEnabled(true);
  ui->player2line->setText("");
}

void GameConfiguration::updateOKButton() {
  bool player1nameentered = ui->player1line->text().isEmpty();
  bool player2nameentered = ui->player2line->text().isEmpty();
  // Get the OK button
  QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
  okButton->setDisabled(player1nameentered || player2nameentered);
}

void GameConfiguration::on_buttonBox_clicked(QAbstractButton *button) {
  if (button == ui->buttonBox->button(QDialogButtonBox::Ok)) {
    if (ui->twoplayermode->isChecked()) {
      qDebug() << "two player mode";
    } else if (ui->AIMode->isChecked()) {
      qDebug() << "AI mode";
    }
  }
}

void GameConfiguration::on_AIMode_clicked() {
  ui->player2line->setText(Data::ainame);
  ui->player2line->setDisabled(true);
}

void GameConfiguration::on_twoplayermode_clicked() {
  if (ui->player2line->text() == Data::ainame) {
    ui->player2line->setText("");
    ui->player2line->setEnabled(true);
  }
}
