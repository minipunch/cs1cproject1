/********************************************************************************
** Form generated from reading UI file 'mempurchlist.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMPURCHLIST_H
#define UI_MEMPURCHLIST_H

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

class Ui_mempurchList
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *mempurchList)
    {
        if (mempurchList->objectName().isEmpty())
            mempurchList->setObjectName(QStringLiteral("mempurchList"));
        mempurchList->resize(400, 300);
        buttonBox = new QDialogButtonBox(mempurchList);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(mempurchList);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 110, 191, 21));
        label = new QLabel(mempurchList);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 110, 101, 20));

        retranslateUi(mempurchList);
        QObject::connect(buttonBox, SIGNAL(accepted()), mempurchList, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), mempurchList, SLOT(reject()));

        QMetaObject::connectSlotsByName(mempurchList);
    } // setupUi

    void retranslateUi(QDialog *mempurchList)
    {
        mempurchList->setWindowTitle(QApplication::translate("mempurchList", "Dialog", 0));
        label->setText(QApplication::translate("mempurchList", "Name or Id Number", 0));
    } // retranslateUi

};

namespace Ui {
    class mempurchList: public Ui_mempurchList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMPURCHLIST_H
