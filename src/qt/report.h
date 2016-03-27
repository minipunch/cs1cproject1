#ifndef REPORT_H
#define REPORT_H
#include "Store.h"
#include <QDialog>

namespace Ui {
class Report;
}
/*!
 * \brief Class for the "Sales Report" button
 */
class Report : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Constructor
     * \param parent
     */
    explicit Report(QWidget *parent = 0);
    /*!
     * \brief gets the date input by the user
     * \return user's date input
     */
    Date getDate();
    /*!
     * \brief Whether or not user wants members sorted by type in the report
     * \return user's choice for sorting
     */
    bool getCheq();
    /*!
         * \brief destructor
         */
    ~Report();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_checkBox_clicked();

private:
    Ui::Report *ui;
    Date date;
    bool cheq;


    /*!
     * \file report.h
     * \brief  Header for report class, used for sales report button
     *
     * This file contains all of the attributes mempurch list class
     */
};

#endif // REPORT_H
