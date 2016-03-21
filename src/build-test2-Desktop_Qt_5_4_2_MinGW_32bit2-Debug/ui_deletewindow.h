/********************************************************************************
** Form generated from reading UI file 'deletewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEWINDOW_H
#define UI_DELETEWINDOW_H

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

class Ui_DeleteWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *DeleteWindow)
    {
        if (DeleteWindow->objectName().isEmpty())
            DeleteWindow->setObjectName(QStringLiteral("DeleteWindow"));
        DeleteWindow->resize(207, 212);
        buttonBox = new QDialogButtonBox(DeleteWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 110, 191, 51));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        lineEdit = new QLineEdit(DeleteWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 80, 141, 20));
        label = new QLabel(DeleteWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 51, 16));

        retranslateUi(DeleteWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), DeleteWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DeleteWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(DeleteWindow);
    } // setupUi

    void retranslateUi(QDialog *DeleteWindow)
    {
        DeleteWindow->setWindowTitle(QApplication::translate("DeleteWindow", "Delete existing member", 0));
        label->setText(QApplication::translate("DeleteWindow", "Full Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class DeleteWindow: public Ui_DeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEWINDOW_H
