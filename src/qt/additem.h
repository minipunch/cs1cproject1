#ifndef AddItem_H
#define AddItem_H

#include <QDialog>
#include "Store.h"

namespace Ui {

class AddItem;
}
/*!
 * \brief Class for adding items
 *
 * This class brings up a dialog window so a user can add a new item
 */
class AddItem : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Constructor
     * \param parent
     */
    explicit AddItem(QWidget *parent = 0);
    /*!
     * \brief Returns new Item
     *
     * Sends an item pointer back to mainwindow to be validated and added
     * to the item list if it is valid.
     * \return New items
     */
    Item* GetItem();
    /*!
         * \brief destructor
         */
    ~AddItem();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddItem *ui;
    Item *dItem;


    /*!
     * \file additem.h
     * \brief  Header file for adding items
     *
     * This file contains all of the declarations of the additem class
     */
};

#endif // AddItem_H
