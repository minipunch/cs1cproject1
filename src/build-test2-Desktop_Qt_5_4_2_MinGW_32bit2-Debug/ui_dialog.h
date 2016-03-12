/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *NameEdit;
    QLineEdit *YearEdit;
    QLineEdit *IdEdit;
    QCheckBox *checkBox;
    QLineEdit *DayEdit;
    QLineEdit *MonthEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(454, 303);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        NameEdit = new QLineEdit(Dialog);
        NameEdit->setObjectName(QStringLiteral("NameEdit"));
        NameEdit->setGeometry(QRect(240, 30, 141, 20));
        YearEdit = new QLineEdit(Dialog);
        YearEdit->setObjectName(QStringLiteral("YearEdit"));
        YearEdit->setGeometry(QRect(340, 130, 51, 20));
        IdEdit = new QLineEdit(Dialog);
        IdEdit->setObjectName(QStringLiteral("IdEdit"));
        IdEdit->setGeometry(QRect(310, 90, 71, 20));
        checkBox = new QCheckBox(Dialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(290, 60, 91, 21));
        DayEdit = new QLineEdit(Dialog);
        DayEdit->setObjectName(QStringLiteral("DayEdit"));
        DayEdit->setGeometry(QRect(310, 130, 21, 20));
        MonthEdit = new QLineEdit(Dialog);
        MonthEdit->setObjectName(QStringLiteral("MonthEdit"));
        MonthEdit->setGeometry(QRect(280, 130, 21, 20));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 30, 41, 21));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 130, 31, 21));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 90, 21, 21));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Add a new member", 0));
        checkBox->setText(QApplication::translate("Dialog", " <- Executive", 0));
        label->setText(QApplication::translate("Dialog", "Name: ", 0));
        label_2->setText(QApplication::translate("Dialog", "Date: ", 0));
        label_3->setText(QApplication::translate("Dialog", "ID:", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
