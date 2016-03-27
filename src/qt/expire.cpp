#include "expire.h"
#include "ui_expire.h"
/*!
 * \file expire.cpp
 * \brief Source file for expire class methods
 *
 * This file contains all of the definitions for the expire class
 */
expire::expire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::expire)
{
    ui->setupUi(this);
}

expire::~expire()
{
    delete ui;
}

void expire::on_buttonBox_accepted()
{
    QString monthTemp = ui->MonthEdit->text();
    string month2 = monthTemp.toStdString();
    month = month2;
}

string expire::getMonth(){
    return this->month;
}

void expire::on_buttonBox_rejected()
{
    this->close();
}
