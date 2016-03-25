#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "executive.h"
namespace Ui {
class Dialog;
}
/*!
 * \brief The Dialog class
 * Structure for the Dialog Object
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    member* GetNewMem();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();



    void on_checkBox_toggled(bool checked);

private:
    Ui::Dialog *ui;
    member *newMem;
    bool isExec;
};

#endif // DIALOG_H
