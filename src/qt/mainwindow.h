#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "member.h"
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

private slots:
    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    deque<member> memDeq;
};

#endif // MAINWINDOW_H
