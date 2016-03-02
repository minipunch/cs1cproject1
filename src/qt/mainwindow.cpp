#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"
#include "member.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);  
    bulkClub.readIn();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_9_clicked()
{


    for(int i = 0; i < bulkClub.getMemCount(); i++)
    {
    ui->listWidget->addItem(QString::fromStdString(bulkClub.PrintMember(i)));
    }

   // ui->listWidget->addItem(QString::fromStdString(bulkClub.PrintMember(1)));
}

void MainWindow::setDate()
{
    Date today;
    ui->label_2->setText(QString::fromStdString("Date: " + today.DisplayDate()));
}

Store MainWindow::getStore() {
    return this->bulkClub;
}


