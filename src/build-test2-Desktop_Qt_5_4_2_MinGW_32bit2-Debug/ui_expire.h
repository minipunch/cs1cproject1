/********************************************************************************
** Form generated from reading UI file 'expire.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPIRE_H
#define UI_EXPIRE_H

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

class Ui_expire
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *MonthEdit;

    void setupUi(QDialog *expire)
    {
        if (expire->objectName().isEmpty())
            expire->setObjectName(QStringLiteral("expire"));
        expire->resize(400, 300);
        buttonBox = new QDialogButtonBox(expire);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-70, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(expire);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 90, 101, 16));
        MonthEdit = new QLineEdit(expire);
        MonthEdit->setObjectName(QStringLiteral("MonthEdit"));
        MonthEdit->setGeometry(QRect(140, 110, 91, 20));

        retranslateUi(expire);
        QObject::connect(buttonBox, SIGNAL(accepted()), expire, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), expire, SLOT(reject()));

        QMetaObject::connectSlotsByName(expire);
    } // setupUi

    void retranslateUi(QDialog *expire)
    {
        expire->setWindowTitle(QApplication::translate("expire", "Dialog", 0));
        label->setText(QApplication::translate("expire", "Month of Expiration", 0));
    } // retranslateUi

};

namespace Ui {
    class expire: public Ui_expire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPIRE_H
