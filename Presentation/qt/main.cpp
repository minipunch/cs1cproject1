#include "mainwindow.h"
#include <QApplication>
/*!
 * \file main.cpp
 * \brief shows the main window
 *
 * Main contains the instances of the mainwindow object and shows it
 */
/*!
 * \brief main
 * \param argc
 * \param argv
 * \return a.exec()
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
