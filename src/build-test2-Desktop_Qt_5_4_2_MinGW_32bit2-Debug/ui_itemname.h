/********************************************************************************
** Form generated from reading UI file 'itemname.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMNAME_H
#define UI_ITEMNAME_H

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

class Ui_ItemName
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *name;

    void setupUi(QDialog *ItemName)
    {
        if (ItemName->objectName().isEmpty())
            ItemName->setObjectName(QStringLiteral("ItemName"));
        ItemName->resize(400, 300);
        buttonBox = new QDialogButtonBox(ItemName);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-60, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(ItemName);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 70, 71, 16));
        name = new QLineEdit(ItemName);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(150, 100, 113, 20));

        retranslateUi(ItemName);
        QObject::connect(buttonBox, SIGNAL(accepted()), ItemName, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ItemName, SLOT(reject()));

        QMetaObject::connectSlotsByName(ItemName);
    } // setupUi

    void retranslateUi(QDialog *ItemName)
    {
        ItemName->setWindowTitle(QApplication::translate("ItemName", "Dialog", 0));
        label->setText(QApplication::translate("ItemName", "Item name", 0));
    } // retranslateUi

};

namespace Ui {
    class ItemName: public Ui_ItemName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMNAME_H
