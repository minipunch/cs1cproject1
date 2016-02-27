#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"
#include "member.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int x = 0; x < 15; ++x)
    {
        member *temp = new member;
        memDeq.push_back(*temp);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_9_clicked()
{


    for(int x = 0; x < 15; ++x)
    {
        ui->listWidget->addItem(QString::fromStdString(memDeq.at(x).getName()));
    }

    // old test stuff below
    //josh.setName("Bill Gates");
   //ui->label_2->setText(QString::fromStdString(josh.getName()));
}

void MainWindow::setDate()
{
    Date today;
    ui->label_2->setText(QString::fromStdString("Date: " + today.DisplayDate()));
}


