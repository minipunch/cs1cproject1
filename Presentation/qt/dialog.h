#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "executive.h"
namespace Ui {
class Dialog;
}
/*!
 * \brief Class for adding a member
 *
 * This class brings up a dialog menu so the user can add a new member to the store.
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Constructor
     * \param parent
     */
    explicit Dialog(QWidget *parent = 0);
    /*!
         * \brief destructor
         */
    ~Dialog();
    /*!
     * \brief gets the new member
     *
     * Returns the new member pointer to mainwindow
     * \return the new member pointer
     */
    member* GetNewMem();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();



    void on_checkBox_toggled(bool checked);

private:
    Ui::Dialog *ui;
    member *newMem;
    bool isExec;

    /*!
     * \file dialog.h
     * \brief  Header for dialog class
     *
     * This file contains all of the declarations of the dialog class
     */

};

#endif // DIALOG_H
