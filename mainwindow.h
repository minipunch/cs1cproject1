#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Store.h"
#include <deque>
#include "dialog.h"
#include "deletewindow.h"
#include "mempurchlist.h"
#include "itemnames.h"
#include "additem.h"
#include "deleteitem.h"
#include "report.h"
#include "itemname.h"
namespace Ui {
class MainWindow;
}

/*!
 * \brief The MainWindow class
 *  Structure managing the Main Window of the GUI
 *  Sets the date, manages the display, gets the
 *  store data and files.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setDate();
    void displayMembers(member mem);
    Store getStore();
    string getFilename() const;

private slots:
    void on_pushButton_clicked();       /*!< function for the---Button
    void on_pushButton_9_clicked();     /*!< function for the---Button
    void on_pushButton_10_clicked();    /*!< function for the ---Button

    void on_pushButton_8_clicked();     /*!< function for the ---Button

    void on_pushButton_11_clicked();    /*!< function for the ---Button

    void on_addmem_clicked();           /*!< function for the ----Button

    void on_pushButton_12_clicked();    /*!< function for the---Button

    void on_pushButton_7_clicked();     /*!< function for the ---Button

    void on_pushButton_13_clicked();    /*!<function for the ---Button

    void on_pushButton_6_clicked();     /*!<function for the ---Button

    void on_pushButton_15_clicked();    /*!<function for the ---Button

    void on_pushButton_16_clicked();    /*!<function for the ---Button

    void on_pushButton_2_clicked();     /*!<function for the ---Button

    void on_pushButton_5_clicked();     /*!<function for the ---Button

    void on_pushButton_3_clicked();     /*!<function for the ---Button

    void on_pushButton_14_clicked();    /*!<fuction for the ---Button

private:
    Ui::MainWindow *ui;
    Store bulkClub;                     /*!< instance of Store Class
    string filename;                    /*!< first filename
    string filenameI;                   /*!< second filename
    string filenameIS;                  /*!< save file
    Dialog newMem;                      /*!< instance of Dialog
    DeleteWindow deleteMember;          /*!< instance of deleting Window member
    mempurchList purchList;             /*!< instance of purchaseList
    AddItem itemAdd;                    /*!< instance of Adding an Item
    deleteitem itemDel;                 /*!< instance of deleting item
    ItemName item;                      /*!< for naming an item
    Report rep;                         /*!< for generating/tracking a report
};

#endif // MAINWINDOW_H
