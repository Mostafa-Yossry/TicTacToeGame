/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *registerbutton;
    QLabel *label_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *user;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *pass;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(400, 300);
        registerbutton = new QPushButton(Form);
        registerbutton->setObjectName("registerbutton");
        registerbutton->setGeometry(QRect(120, 190, 75, 24));
        label_3 = new QLabel(Form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 20, 161, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        label_3->setFont(font);
        widget = new QWidget(Form);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 70, 193, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        user = new QLineEdit(widget);
        user->setObjectName("user");

        horizontalLayout->addWidget(user);

        widget1 = new QWidget(Form);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(60, 130, 191, 24));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        pass = new QLineEdit(widget1);
        pass->setObjectName("pass");
        pass->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(pass);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        registerbutton->setText(QCoreApplication::translate("Form", "Register", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "Sign Up", nullptr));
        label->setText(QCoreApplication::translate("Form", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
