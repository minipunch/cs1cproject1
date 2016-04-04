#ifndef EXPIRE_H
#define EXPIRE_H

#include <QDialog>
#include "Store.h"

namespace Ui {
class expire;
}
/*!
 * \brief Class to show the expirations for a certain month
 *
 * User can input a month and get the members that expire that month and the cost to renew.
 */
class expire : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief constructor
     * \param parent
     */
    explicit expire(QWidget *parent = 0);
    /*!
     * \brief gets the month that was input
     * \return month input
     */
    string getMonth();\
    /*!
         * \brief destructor
         */
    ~expire();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::expire *ui;
    string month;
};

/*!
 * \file expire.h
 * \brief  Header for expire class
 *
 * This file contains all of the declarations of the expire class
 */

#endif // EXPIRE_H
