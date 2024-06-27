/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm {
 public:
  QPushButton *loginbutton;
  QLabel *label_3;
  QWidget *widget;
  QHBoxLayout *horizontalLayout;
  QLabel *label;
  QLineEdit *use;
  QWidget *widget1;
  QHBoxLayout *horizontalLayout_2;
  QLabel *label_2;
  QLineEdit *pas;

  void setupUi(QWidget *LoginForm) {
    if (LoginForm->objectName().isEmpty())
      LoginForm->setObjectName("LoginForm");
    LoginForm->resize(400, 300);
    loginbutton = new QPushButton(LoginForm);
    loginbutton->setObjectName("loginbutton");
    loginbutton->setGeometry(QRect(120, 190, 75, 24));
    label_3 = new QLabel(LoginForm);
    label_3->setObjectName("label_3");
    label_3->setGeometry(QRect(60, 20, 81, 21));
    QFont font;
    font.setFamilies({QString::fromUtf8("Arial")});
    font.setPointSize(14);
    font.setBold(true);
    font.setItalic(true);
    label_3->setFont(font);
    widget = new QWidget(LoginForm);
    widget->setObjectName("widget");
    widget->setGeometry(QRect(60, 80, 194, 24));
    horizontalLayout = new QHBoxLayout(widget);
    horizontalLayout->setObjectName("horizontalLayout");
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    label = new QLabel(widget);
    label->setObjectName("label");

    horizontalLayout->addWidget(label);

    use = new QLineEdit(widget);
    use->setObjectName("use");

    horizontalLayout->addWidget(use);

    widget1 = new QWidget(LoginForm);
    widget1->setObjectName("widget1");
    widget1->setGeometry(QRect(60, 140, 191, 24));
    horizontalLayout_2 = new QHBoxLayout(widget1);
    horizontalLayout_2->setObjectName("horizontalLayout_2");
    horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
    label_2 = new QLabel(widget1);
    label_2->setObjectName("label_2");

    horizontalLayout_2->addWidget(label_2);

    pas = new QLineEdit(widget1);
    pas->setObjectName("pas");
    pas->setEchoMode(QLineEdit::Password);

    horizontalLayout_2->addWidget(pas);

    retranslateUi(LoginForm);

    QMetaObject::connectSlotsByName(LoginForm);
  }  // setupUi

  void retranslateUi(QWidget *LoginForm) {
    LoginForm->setWindowTitle(
        QCoreApplication::translate("LoginForm", "Form", nullptr));
    loginbutton->setText(
        QCoreApplication::translate("LoginForm", "Login", nullptr));
    label_3->setText(
        QCoreApplication::translate("LoginForm", "Sign in", nullptr));
    label->setText(
        QCoreApplication::translate("LoginForm", "Username", nullptr));
    label_2->setText(
        QCoreApplication::translate("LoginForm", "Password", nullptr));
  }  // retranslateUi
};

namespace Ui {
class LoginForm : public Ui_LoginForm {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_LOGINFORM_H
