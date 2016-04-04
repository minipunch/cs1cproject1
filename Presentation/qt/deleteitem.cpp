#include "deleteitem.h"
#include "ui_deleteitem.h"
#include <QMessageBox>
/*!
 * \file deleteitem.cpp
 * \brief Source file for deleteitem class methods
 *
 * This file contains all of the definitions for the deleteitem class
 */
deleteitem::deleteitem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteitem)
{
    dName = "NONE";
    ui->setupUi(this);
}

deleteitem::~deleteitem()
{
    delete ui;
}

void deleteitem::on_buttonBox_accepted()
{
    // grab text from the line edit field
    QString nameQ = this->ui->name->text();
    if(nameQ.isEmpty())
    {
        QMessageBox::information(this, tr("Invalid input"),
                   "Please verify input before submitting");
    }
    else
    {
        // convert to STD string
        string name = nameQ.toStdString();
        dName = name;

    }

}
string deleteitem::delItem(){
    return this->dName;
}

void deleteitem::on_buttonBox_rejected()
{
    dName = "NONE";
    this->close();
}
