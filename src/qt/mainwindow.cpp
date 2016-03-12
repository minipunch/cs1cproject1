#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"
#include "member.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->filename = "Empty";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->listWidget->clear();


//    if(this->filename == "Empty")
//    {
//        QMessageBox::information(this,tr("Error!"),"You must first import a member file before printing it.");
//    }
//    else if(this->filename == "")
//    {
//        QMessageBox::information(this,tr("Error!"),"You must first import a member file before printing it.");
//    }
    if(bulkClub.getMemCount() != 0)
    {
        for(int i = 0; i < bulkClub.getMemCount(); i++)
        {
        ui->listWidget->addItem(QString::fromStdString(bulkClub.PrintMember(i)));
        }


    }
    else
    {

        QMessageBox::information(this,tr("Error!"),"You must first import a member file before printing it.");
}
}
void MainWindow::setDate()
{
    //    Date today;
    //    ui->label_2->setText(QString::fromStdString("Date: " + today.DisplayDate()));
    //
}

Store MainWindow::getStore() {
    return this->bulkClub;
}

//read in members
void MainWindow::on_pushButton_10_clicked()
{

    QString filenameQ = QFileDialog::getOpenFileName(
                this,
                tr("Import members"),
                "C://",
                "Text File (*.txt)"
                );
    this->filename = filenameQ.toStdString();
    this->bulkClub.setFilename(filenameQ.toStdString());

    this->bulkClub.readInMembers();
}

string MainWindow::getFilename() const {
    return this->filename;
}

//print items
void MainWindow::on_pushButton_8_clicked()
{
    ui->listWidget->clear();

    if(this->filenameI == "Empty")
    {
        QMessageBox::information(this,tr("Error!"),"You must first import a purchase file before printing it.");
    }
    else if(this->filenameI == "")
    {
        QMessageBox::information(this,tr("Error!"),"You must first import a purchase file before printing it.");
    }
    else
    {

            for(int i = 0; i < bulkClub.getItemCount(); i++)
            {
            ui->listWidget->addItem(QString::fromStdString(bulkClub.PrintItem(i)));
            }

}
}
//import day file
void MainWindow::on_pushButton_11_clicked()
{
    if(bulkClub.getMemCount() !=0)
    {
        QString filenameQ = QFileDialog::getOpenFileName(
                    this,
                    tr("Import a purchase file"),
                    "C://",
                    "Text File (*.txt)"
                    );
        this->filenameI = filenameQ.toStdString();
        this->bulkClub.setFilenameI(filenameQ.toStdString());

        this->bulkClub.readItems();
    }
    else
    {
        QMessageBox::information(this,tr("Error!"),"Member database empty, please import a member list first.");
    }
}
void MainWindow::on_addmem_clicked()
{

    newMem.exec();

    member *addPtr = newMem.GetNewMem();
    if(addPtr != NULL)
    {
        bulkClub.addMember(addPtr);
    }
    else
    {
         QMessageBox::information(this,tr("Action Cancelled!"),"No Members added.");
    }
    bulkClub.sortingMems(NAME);

}

void MainWindow::on_pushButton_12_clicked()
{
    if(bulkClub.getMemCount() !=0)
    {
        bulkClub.saveMembers();
        QMessageBox::information(this,tr("List Saved!"),"Your members list has been saved to the file.");
    }
    else
    {
         QMessageBox::information(this,tr("Error!"),"Member database empty, please import a member list first.");
    }
}
