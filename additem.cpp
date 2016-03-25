#include "additem.h"
#include "ui_AddItem.h"

/*!
 * \brief AddItem::AddItem
 * \param parent
 */

AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
}
/*!
 * \brief AddItem::~AddItem
 */
AddItem::~AddItem()
{
    delete ui;
}
/*!
 * \brief AddItem::on_buttonBox_accepted
 */
void AddItem::on_buttonBox_accepted()
{
    Date date;
    QString name = ui->Item->text(); /*!< Name of the member */
    QString price = ui->Price->text();
    QString id = ui->ID->text();
    QString quantity = ui->Quantity->text();
    QString monthTemp = ui->MonthEdit->text();
    QString dayTemp = ui->DayEdit->text();
    QString yearTemp = ui->YearEdit->text();

    dItem = new Item;
    string nameStr = name.toStdString();
    float p = price.toFloat();
    double ID = id.toDouble();
    int q = quantity.toInt();

    int month = monthTemp.toInt();
    int day = dayTemp.toInt();
    int year = yearTemp.toInt();
    date.SetDate(month, day, year);

    dItem->SetAll(nameStr,p,q,date,ID);
}
/*!
 * \brief AddItem::on_buttonBox_rejected
 */
void AddItem::on_buttonBox_rejected()
{
    dItem = NULL;
    this->close();
}
/*!
 * \brief AddItem::GetItem
 * \return
 */
Item * AddItem::GetItem()
{
    return this->dItem;
}
