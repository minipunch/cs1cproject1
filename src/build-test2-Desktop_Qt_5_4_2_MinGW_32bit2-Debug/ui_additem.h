/********************************************************************************
** Form generated from reading UI file 'additem.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEM_H
#define UI_ADDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddItem
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *Item;
    QLabel *label;
    QLineEdit *Price;
    QLabel *label_2;
    QLineEdit *ID;
    QLabel *label_3;
    QLineEdit *Quantity;
    QLabel *label_4;
    QLineEdit *DayEdit;
    QLineEdit *YearEdit;
    QLabel *label_5;
    QLineEdit *MonthEdit;

    void setupUi(QDialog *AddItem)
    {
        if (AddItem->objectName().isEmpty())
            AddItem->setObjectName(QStringLiteral("AddItem"));
        AddItem->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddItem);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-80, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        Item = new QLineEdit(AddItem);
        Item->setObjectName(QStringLiteral("Item"));
        Item->setGeometry(QRect(130, 40, 113, 20));
        label = new QLabel(AddItem);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 20, 91, 16));
        Price = new QLineEdit(AddItem);
        Price->setObjectName(QStringLiteral("Price"));
        Price->setGeometry(QRect(130, 80, 113, 20));
        label_2 = new QLabel(AddItem);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 60, 91, 16));
        ID = new QLineEdit(AddItem);
        ID->setObjectName(QStringLiteral("ID"));
        ID->setGeometry(QRect(130, 120, 113, 20));
        label_3 = new QLabel(AddItem);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 140, 91, 16));
        Quantity = new QLineEdit(AddItem);
        Quantity->setObjectName(QStringLiteral("Quantity"));
        Quantity->setGeometry(QRect(130, 160, 113, 20));
        label_4 = new QLabel(AddItem);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 100, 71, 20));
        DayEdit = new QLineEdit(AddItem);
        DayEdit->setObjectName(QStringLiteral("DayEdit"));
        DayEdit->setGeometry(QRect(160, 200, 21, 20));
        YearEdit = new QLineEdit(AddItem);
        YearEdit->setObjectName(QStringLiteral("YearEdit"));
        YearEdit->setGeometry(QRect(190, 200, 51, 20));
        label_5 = new QLabel(AddItem);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 180, 31, 21));
        MonthEdit = new QLineEdit(AddItem);
        MonthEdit->setObjectName(QStringLiteral("MonthEdit"));
        MonthEdit->setGeometry(QRect(130, 200, 21, 20));

        retranslateUi(AddItem);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddItem, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddItem, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddItem);
    } // setupUi

    void retranslateUi(QDialog *AddItem)
    {
        AddItem->setWindowTitle(QApplication::translate("AddItem", "Dialog", 0));
        label->setText(QApplication::translate("AddItem", "Item name", 0));
        label_2->setText(QApplication::translate("AddItem", "Price", 0));
        label_3->setText(QApplication::translate("AddItem", "Quantity", 0));
        label_4->setText(QApplication::translate("AddItem", "ID", 0));
        label_5->setText(QApplication::translate("AddItem", "Date: ", 0));
    } // retranslateUi

};

namespace Ui {
    class AddItem: public Ui_AddItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEM_H
