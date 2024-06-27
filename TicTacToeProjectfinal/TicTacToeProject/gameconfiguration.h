#ifndef GAMECONFIGURATION_H
#define GAMECONFIGURATION_H
#include <QDialog>
#include <QPushButton>

namespace Ui {
class GameConfiguration;
}
struct Data {
  static constexpr const char* ainame = "AI";
};

enum Mode { twoplayer, AI };

class GameConfiguration : public QDialog {
  Q_OBJECT
 private:
  explicit GameConfiguration(QWidget* parent = nullptr);

 public:
  ~GameConfiguration();
  // setter of players names
  void setplayer1name(const QString& name) const;
  void setplayer2name(const QString& name) const;
  // get players name
  QString getplayer1name() const;
  QString getplayer2name() const;
  Mode getMode() const;
  // singleton
  static GameConfiguration* getInstance();
  // function to reset some configurations
  void resetsomeconfig();

 public slots:
  // ok button of configuration window
  void updateOKButton();

 private slots:
  void on_buttonBox_clicked(QAbstractButton* button);

  void on_AIMode_clicked();

  void on_twoplayermode_clicked();

 private:
  Ui::GameConfiguration* ui;
  static GameConfiguration* gameconfig;
};

#endif  // GAMECONFIGURATION_H
