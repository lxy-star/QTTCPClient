/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *HostLineEdit;
    QLineEdit *PortLineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *connectButton;
    QPushButton *pushButton_2;
    QLabel *label_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        HostLineEdit = new QLineEdit(Widget);
        HostLineEdit->setObjectName("HostLineEdit");
        HostLineEdit->setGeometry(QRect(320, 200, 171, 31));
        PortLineEdit = new QLineEdit(Widget);
        PortLineEdit->setObjectName("PortLineEdit");
        PortLineEdit->setGeometry(QRect(320, 260, 171, 31));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 210, 69, 19));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 260, 69, 19));
        connectButton = new QPushButton(Widget);
        connectButton->setObjectName("connectButton");
        connectButton->setGeometry(QRect(310, 340, 93, 28));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(420, 340, 93, 28));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(360, 100, 91, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Host:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Port:", nullptr));
        connectButton->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\256\242\346\210\267\347\253\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
