/********************************************************************************
** Form generated from reading UI file 'report.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORT_H
#define UI_REPORT_H

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

class Ui_Report
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *DayEdit;
    QLabel *label_2;
    QLineEdit *MonthEdit;
    QLineEdit *YearEdit;
    QCheckBox *checkBox;

    void setupUi(QDialog *Report)
    {
        if (Report->objectName().isEmpty())
            Report->setObjectName(QStringLiteral("Report"));
        Report->resize(400, 300);
        buttonBox = new QDialogButtonBox(Report);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-70, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        DayEdit = new QLineEdit(Report);
        DayEdit->setObjectName(QStringLiteral("DayEdit"));
        DayEdit->setGeometry(QRect(190, 120, 21, 20));
        label_2 = new QLabel(Report);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 120, 31, 21));
        MonthEdit = new QLineEdit(Report);
        MonthEdit->setObjectName(QStringLiteral("MonthEdit"));
        MonthEdit->setGeometry(QRect(160, 120, 21, 20));
        YearEdit = new QLineEdit(Report);
        YearEdit->setObjectName(QStringLiteral("YearEdit"));
        YearEdit->setGeometry(QRect(220, 120, 51, 20));
        checkBox = new QCheckBox(Report);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(130, 90, 171, 17));

        retranslateUi(Report);
        QObject::connect(buttonBox, SIGNAL(accepted()), Report, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Report, SLOT(reject()));

        QMetaObject::connectSlotsByName(Report);
    } // setupUi

    void retranslateUi(QDialog *Report)
    {
        Report->setWindowTitle(QApplication::translate("Report", "Dialog", 0));
        label_2->setText(QApplication::translate("Report", "Date: ", 0));
        checkBox->setText(QApplication::translate("Report", "Sort by Membership Type", 0));
    } // retranslateUi

};

namespace Ui {
    class Report: public Ui_Report {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORT_H
