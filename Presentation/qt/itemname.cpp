#include "itemname.h"
#include "ui_itemname.h"
#include "Store.h"
#include <QMessageBox>
/*!
 * \file itemname.cpp
 * \brief Source file for itemname class methods
 *
 * This file contains all of the definitions for the itemname class
 */
ItemName::ItemName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemName)
{
    ui->setupUi(this);
    name = "None";
}

ItemName::~ItemName()
{
    delete ui;
}

void ItemName::on_buttonBox_accepted()
{
    // grab text from the line edit field
    QString nameQ = this->ui->name->text();
    if(nameQ.isEmpty() !=0)
    {
        QMessageBox::information(this, tr("Invalid input"),
                      "Please verify input before submitting");
    }
    else
    {
        // convert to STD string
        string name1 = nameQ.toStdString();
        name = name1;
    }

}
string ItemName::getItem(){
    return name;
}

void ItemName::on_buttonBox_rejected()
{
    this->close();
}
