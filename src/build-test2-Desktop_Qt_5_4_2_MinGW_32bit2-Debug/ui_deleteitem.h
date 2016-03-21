/********************************************************************************
** Form generated from reading UI file 'deleteitem.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEITEM_H
#define UI_DELETEITEM_H

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

class Ui_deleteitem
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *name;
    QLabel *label;

    void setupUi(QDialog *deleteitem)
    {
        if (deleteitem->objectName().isEmpty())
            deleteitem->setObjectName(QStringLiteral("deleteitem"));
        deleteitem->resize(400, 300);
        buttonBox = new QDialogButtonBox(deleteitem);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        name = new QLineEdit(deleteitem);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(130, 120, 113, 20));
        label = new QLabel(deleteitem);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 100, 47, 13));

        retranslateUi(deleteitem);
        QObject::connect(buttonBox, SIGNAL(accepted()), deleteitem, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), deleteitem, SLOT(reject()));

        QMetaObject::connectSlotsByName(deleteitem);
    } // setupUi

    void retranslateUi(QDialog *deleteitem)
    {
        deleteitem->setWindowTitle(QApplication::translate("deleteitem", "Dialog", 0));
        label->setText(QApplication::translate("deleteitem", "Item", 0));
    } // retranslateUi

};

namespace Ui {
    class deleteitem: public Ui_deleteitem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEITEM_H
