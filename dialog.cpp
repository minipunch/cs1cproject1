#include "dialog.h"
#include "ui_dialog.h"
#include<QString>
/*!
 * \brief Dialog::Dialog
 * \param parent
 */
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    newMem = NULL;
    ui->setupUi(this);
    isExec = false;
}
/*!
 * \brief Dialog::~Dialog
 */
Dialog::~Dialog()
{
    delete ui;
}
/*!
 * \brief Dialog::on_buttonBox_accepted
 */
void Dialog::on_buttonBox_accepted()
{   Date date;

    QString name = ui->NameEdit->text();
    QString idTemp = ui->IdEdit->text();
    QString monthTemp = ui->MonthEdit->text();
    QString dayTemp = ui->DayEdit->text();
    QString yearTemp = ui->YearEdit->text();

    string nameStr = name.toStdString();
    double id = idTemp.toDouble();
    int month = monthTemp.toInt();
    int day = dayTemp.toInt();
    int year = yearTemp.toInt();
    date.SetDate(month, day, year);

    executive *newEx;

    if(isExec)
    {
        newEx = new executive;
        newEx->setAll(nameStr,"Executive", id, date, .035);
        newMem = newEx;

    }
    else
    {
        newMem = new member;
          newMem->setAll(nameStr,"Regular", id, date);
    }


}
/*!
 * \brief Dialog::GetNewMem
 * \return
 */
member * Dialog::GetNewMem()
{
    return this->newMem;
}
/*!
 * \brief Dialog::on_buttonBox_rejected
 */
void Dialog::on_buttonBox_rejected()
{

    newMem = NULL;
    this->close();
}
/*!
 * \brief Dialog::on_checkBox_toggled
 * \param checked
 */
void Dialog::on_checkBox_toggled(bool checked)
{
    isExec = checked;
}
