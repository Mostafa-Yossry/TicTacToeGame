#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void on_loginbutton_clicked();

private:
    Ui::LoginForm *ui;
    bool authenticateUser(const QString &username, const QString &password);

};

#endif // LOGINFORM_H
