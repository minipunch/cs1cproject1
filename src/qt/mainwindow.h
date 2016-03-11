#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Store.h"
#include <deque>
#include "dialog.h"
#include "itemnames.h"
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
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_addmem_clicked();

private:
    Ui::MainWindow *ui;
    Store bulkClub;
    string filename;
    string filenameI;
    Dialog newMem;
};

#endif // MAINWINDOW_H
