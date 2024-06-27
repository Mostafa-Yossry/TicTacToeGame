#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget {
  Q_OBJECT

 public:
  explicit Form(QWidget *parent = nullptr);
  ~Form();

 private slots:
  void on_registerbutton_clicked();

 private:
  Ui::Form *ui;
  bool registerUser(const QString &username, const QString &password);
};

#endif  // FORM_H
