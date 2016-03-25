#include "itemname.h"
#include "ui_itemname.h"
#include "Store.h"
/*!
 * \brief ItemName::ItemName
 * \param parent
 */
ItemName::ItemName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemName)
{
    ui->setupUi(this);
}
/*!
 * \brief ItemName::~ItemName
 */
ItemName::~ItemName()
{
    delete ui;
}
/*!
 * \brief ItemName::on_buttonBox_accepted
 */
void ItemName::on_buttonBox_accepted()
{
    // grab text from the line edit field
    QString nameQ = this->ui->name->text();
    // convert to STD string
    string name1 = nameQ.toStdString();
    name = name1;
}
/*!
 * \brief ItemName::getItem
 * \return
 */
string ItemName::getItem(){
    return name;
}
/*!
 * \brief ItemName::on_buttonBox_rejected
 */
void ItemName::on_buttonBox_rejected()
{
    this->close();
}
