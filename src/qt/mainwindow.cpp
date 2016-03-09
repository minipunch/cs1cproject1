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

    if(this->filename == "Empty")
    {
        QMessageBox::information(this,tr("Error!"),"You must first import a member file before printing it.");
    }
    else if(this->filename == "")
    {
        QMessageBox::information(this,tr("Error!"),"You must first import a member file before printing it.");
    }
    else
    {

            for(int i = 0; i < bulkClub.getMemCount(); i++)
            {
            ui->listWidget->addItem(QString::fromStdString(bulkClub.PrintMember(i)));
            }



    //ui->listWidget->addItem(QString::fromStdString(bulkClub.PrintMember(1)));

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
