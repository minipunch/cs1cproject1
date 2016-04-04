#ifndef ITEMNAME_H
#define ITEMNAME_H
#include "Store.h"
#include <QDialog>

namespace Ui {
class ItemName;
}
/*!
 * \brief Class to show statistics for a specific item
 *
 * This class allows the user to input an item name and get information on it
 * such as, total number bought and total revenue
 */
class ItemName : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Constructor
     * \param parent
     */
    explicit ItemName(QWidget *parent = 0);
    /*!
     * \brief gets the item name
     * \return name of item to be search
     */
    string getItem();
    /*!
         * \brief destructor
         */
    ~ItemName();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ItemName *ui;
    string name;


    /*!
     * \file itemname.h
     * \brief  Header for Itemname class
     *
     * This file contains all declarations for the Itemname class
     */
};

#endif // ITEMNAME_H
