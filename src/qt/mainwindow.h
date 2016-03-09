#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Store.h"
#include <deque>

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

private:
    Ui::MainWindow *ui;
    Store bulkClub;
    string filename;
    string filenameI;
};

#endif // MAINWINDOW_H
