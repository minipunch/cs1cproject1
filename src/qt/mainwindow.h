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
#include "expire.h"
namespace Ui {
class MainWindow;
}

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
    void on_pushButton_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_addmem_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::MainWindow *ui;
    Store bulkClub;
    string filename;
    string filenameI;
    string filenameIS;
    Dialog newMem;
    DeleteWindow deleteMember;
    mempurchList purchList;
    AddItem itemAdd;
    deleteitem itemDel;
    ItemName item;
    Report rep;
    expire exp;
};

#endif // MAINWINDOW_H
