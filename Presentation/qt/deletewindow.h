#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QDialog>
#include "executive.h"

namespace Ui {
class DeleteWindow;
}
/*!
 * \brief Class for deleting a member
 *
 * Brings up a dialog menu for the user to input a member name to be deleted
 */
class DeleteWindow : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief gets the name input
     *
     * Returns the name of the member to be deleted to mainwindow
     * \return name to delete
     */
    string getDeleteMemberName();
    /*!
     * \brief Constructor
     * \param parent
     */
    explicit DeleteWindow(QWidget *parent = 0);
    /*!
         * \brief destructor
         */
    ~DeleteWindow();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    string deleteMemberName;
    Ui::DeleteWindow *ui;

    /*!
     * \file deletewindow.h
     * \brief  Header for delete window class
     *
     * This file contains all of the declarations of the deletewindow class
     */

};

#endif // DELETEWINDOW_H
