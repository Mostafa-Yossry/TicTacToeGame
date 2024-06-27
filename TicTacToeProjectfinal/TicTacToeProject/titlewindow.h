#ifndef TITLEWINDOW_H
#define TITLEWINDOW_H

#include <gameconfiguration.h>

#include <QMainWindow>
namespace Ui {
class TitleWindow;
}

class TitleWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit TitleWindow(QWidget *parent = nullptr);
  ~TitleWindow();
 signals:
  void startaimode();
 private slots:
  void startnewgame();
  void Boldcurrentplayername();
  void determinegameOutcome();
  void newregister();

 private:
  Ui::TitleWindow *ui;
  GameConfiguration *configuration;
};

#endif  // TITLEWINDOW_H
