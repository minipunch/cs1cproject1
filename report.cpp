#include "report.h"
#include "ui_report.h"
/*!
 * \brief Report::Report
 * \param parent
 */
Report::Report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
}
/*!
 * \brief Report::~Report
 */
Report::~Report()
{
    delete ui;
}
/*!
 * \brief Report::on_buttonBox_accepted
 */
void Report::on_buttonBox_accepted()
{
    Date date1;
    QString monthTemp = ui->MonthEdit->text();
    QString dayTemp = ui->DayEdit->text();
    QString yearTemp = ui->YearEdit->text();

    int month = monthTemp.toInt();
    int day = dayTemp.toInt();
    int year = yearTemp.toInt();
    date1.SetDate(month, day, year);
    date = date1;

}
/*!
 * \brief Report::getDate
 * \return
 */
Date Report::getDate(){
    return this->date;
}
/*!
 * \brief Report::on_buttonBox_rejected
 */
void Report::on_buttonBox_rejected()
{
    this->close();
}
