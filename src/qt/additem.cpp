#include "additem.h"
#include "ui_AddItem.h"
/*!
 * \file additem.cpp
 * \brief Source file for additem class methods
 *
 * This file contains all of the definitions for the additem class
 */
AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::on_buttonBox_accepted()
{
    Date date;
    QString name = ui->Item->text();
    QString price = ui->Price->text();
    QString id = ui->ID->text();
    QString quantity = ui->Quantity->text();
    QString monthTemp = ui->MonthEdit->text();
    QString dayTemp = ui->DayEdit->text();
    QString yearTemp = ui->YearEdit->text();

    dItem = new Item;
    string nameStr = name.toStdString();
    float p = price.toFloat();
    double ID = id.toDouble();
    int q = quantity.toInt();

    int month = monthTemp.toInt();
    int day = dayTemp.toInt();
    int year = yearTemp.toInt();
    date.SetDate(month, day, year);

    dItem->SetAll(nameStr,p,q,date,ID);
}

void AddItem::on_buttonBox_rejected()
{
    dItem = NULL;
    this->close();
}
Item * AddItem::GetItem()
{
    return this->dItem;
}
