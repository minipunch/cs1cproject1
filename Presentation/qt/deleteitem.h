#ifndef DELETEITEM_H
#define DELETEITEM_H

#include <QDialog>
#include "Store.h"

namespace Ui {
class deleteitem;
}
/*!
 * \brief Class for deleting an item
 *
 * Class that brings up a dialog window so the user can enter
 * an item name to remove it from the store
 */
class deleteitem : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief constructor
     * \param parent
     */

    explicit deleteitem(QWidget *parent = 0);
    /*!
     * \brief gets the name of the item to delete
     * \return name of item to be deleted
     */
    string delItem();
    /*!
         * \brief destructor
         */
    ~deleteitem();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::deleteitem *ui;
    string dName;


    /*!
     * \file deleteitem.h
     * \brief  Header for deleteitem class
     *
     * This file contains all of the declarations of the deleteitem class
     */

};

#endif // DELETEITEM_H
