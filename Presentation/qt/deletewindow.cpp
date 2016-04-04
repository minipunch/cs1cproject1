#include "deletewindow.h"
#include "ui_deletewindow.h"
#include <QMessageBox>
/*!
 * \file deletewindow.cpp
 * \brief Source file for deletewindow class methods
 *
 * This file contains all of the definitions for the deletewindow class
 */
DeleteWindow::DeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteWindow)
{
    deleteMemberName = "None";
    ui->setupUi(this);
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::on_buttonBox_accepted()
{
    // grab text from the line edit field
    QString nameQ = this->ui->lineEdit->text();
    if(nameQ.isEmpty())
    {
        QMessageBox::information(this, tr("Invalid input"),
                   "Please verify input before submitting");
    }
    else
    {
        // convert to STD string
        string name = nameQ.toStdString();
        // set private date member for DeleteWindow class. For use in the MainWindow button.
        this->deleteMemberName = name;
    }


}

string DeleteWindow::getDeleteMemberName() {
    return this->deleteMemberName;
}

// CANCEL BUTTON
void DeleteWindow::on_buttonBox_rejected()
{
    deleteMemberName = "None";
    this->close();
}
