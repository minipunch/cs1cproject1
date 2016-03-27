#include "mempurchlist.h"
#include "ui_mempurchlist.h"
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
    toReturn = "12345";
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
}

void mempurchList::on_buttonBox_rejected()
{
    toReturn = "None";
}
