#include "loginform.h"
#include "ui_loginform.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QCryptographicHash>

LoginForm::LoginForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_loginbutton_clicked()
{
    QString username=ui->use->text();
    QString password=ui->pas->text();

    if (authenticateUser(username, password)) {
        QMessageBox::information(this, "Login", "Login successful!");
        // Proceed to game or main application
    } else {
        QMessageBox::warning(this, "Login", "Invalid username or password.");
    }
}
bool LoginForm::authenticateUser(const QString &username, const QString &password) {
    QSqlQuery query;
    QString hashedPassword = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());

    query.prepare("SELECT password FROM users WHERE username = :username");
    query.bindValue(":username", username);
    if (query.exec() && query.next()) {
        QString storedHashedPassword = query.value(0).toString();
        return storedHashedPassword == hashedPassword;
    }
    return false;
}
