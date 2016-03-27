#include "dialog.h"
#include "ui_dialog.h"
#include<QString>
/*!
 * \file dialog.cpp
 * \brief Source file for Dialog class methods
 *
 * This file contains all of the definitions for the Dialog class
 */
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    newMem = NULL;
    ui->setupUi(this);
    isExec = false;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{   Date date;

    QString name = ui->NameEdit->text();
    QString idTemp = ui->IdEdit->text();
    QString monthTemp = ui->MonthEdit->text();
    QString dayTemp = ui->DayEdit->text();
    QString yearTemp = ui->YearEdit->text();

    string nameStr = name.toStdString();
    double id = idTemp.toDouble();
    int month = monthTemp.toInt();
    int day = dayTemp.toInt();
    int year = yearTemp.toInt();
    date.SetDate(month, day, year);

    executive *newEx;

    if(isExec)
    {
        newEx = new executive;
        newEx->setAll(nameStr,"Executive", id, date, .035);
        newMem = newEx;

    }
    else
    {
        newMem = new member;
          newMem->setAll(nameStr,"Regular", id, date);
    }


}
member * Dialog::GetNewMem()
{
    return this->newMem;
}

void Dialog::on_buttonBox_rejected()
{

    newMem = NULL;
    this->close();
}

void Dialog::on_checkBox_toggled(bool checked)
{
    isExec = checked;
}
