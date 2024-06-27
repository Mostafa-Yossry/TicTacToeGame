#include "form.h"

#include <QCryptographicHash>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

#include "ui_form.h"

Form::Form(QWidget *parent) : QWidget(parent), ui(new Ui::Form) {
  ui->setupUi(this);
}

Form::~Form() { delete ui; }

void Form::on_registerbutton_clicked() {
  QString username = ui->user->text();
  QString password = ui->pass->text();
  if (registerUser(username, password)) {
    QMessageBox::information(this, "Registration",
                             "User registered successfully!");
  } else {
    QMessageBox::warning(this, "Registration",
                         "User registration failed. Try a different username.");
  }
}
bool Form::registerUser(const QString &username, const QString &password) {
  QSqlQuery query;
  QString hashedPassword = QString(
      QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256)
          .toHex());

  query.prepare(
      "INSERT INTO users (username, password) VALUES (:username, :password)");
  query.bindValue(":username", username);
  query.bindValue(":password", hashedPassword);

  return query.exec();
}
