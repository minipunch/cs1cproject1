#ifndef MEMPURCHLIST_H
#define MEMPURCHLIST_H

#include <QDialog>

namespace Ui {
class mempurchList;
}
/*!
 * \brief Class for showing information on a specific member
 *
 * This class allows the user to input a name or id number and get information for that member
 * Such as, items they have bought an how much they have spent
 */
class mempurchList : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief constructor
     * \param parent
     */
    explicit mempurchList(QWidget *parent = 0);
    /*!
         * \brief destructor
         */
    ~mempurchList();
    /*!
     * \brief get's the user's input
     * \return user's input(a name or id number)
     */
    QString getString() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::mempurchList *ui;
    QString toReturn;

    /*!
     * \file mempurchlist.h
     * \brief  Header for sorting mempurch list class
     *
     * This file contains all of the attributes mempurch list class
     */
};

#endif // MEMPURCHLIST_H
