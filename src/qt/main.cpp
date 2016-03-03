#include "mainwindow.h"
#include "date.h"
#include "member.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   // string fileNizzame;
    QApplication a(argc, argv);

    MainWindow testapp;
    testapp.show();

    // display current date
    testapp.setDate();


    return a.exec();
}
