#include "mempurchlist.h"
#include "ui_mempurchlist.h"
#include <QMessageBox>
/*!
 * \file mempurchlist.cpp
 * \brief Source file for mempurchlist class methods
 *
 * This file contains all of the definitions for the mempurchlist class
 */
mempurchList::mempurchList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mempurchList)
{
    toReturn = "None";
    ui->setupUi(this);
}

mempurchList::~mempurchList()
{
    delete ui;
}
QString mempurchList::getString() const
{
    return this->toReturn;
}

void mempurchList::on_buttonBox_accepted()
{
    toReturn = this->ui->lineEdit->text();

    if(toReturn.isEmpty())
    {
        QMessageBox::information(this, tr("Invalid input"),
                   "Please verify input before submitting");
        toReturn = "None";
    }
}

void mempurchList::on_buttonBox_rejected()
{
    toReturn = "None";
}
