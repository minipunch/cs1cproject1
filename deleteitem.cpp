#include "deleteitem.h"
#include "ui_deleteitem.h"

/*!
 * \brief deleteitem::deleteitem
 * \param parent
 */
deleteitem::deleteitem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteitem)
{
    ui->setupUi(this);
}
/*!
 * \brief deleteitem::~deleteitem
 */
deleteitem::~deleteitem()
{
    delete ui;
}
/*!
 * \brief deleteitem::on_buttonBox_accepted
 */
void deleteitem::on_buttonBox_accepted()
{
    // grab text from the line edit field
    QString nameQ = this->ui->name->text();
    // convert to STD string
    string name = nameQ.toStdString();
    dName = name;

}
/*!
 * \brief deleteitem::delItem
 * \return
 */
string deleteitem::delItem(){
    return this->dName;
}
/*!
 * \brief deleteitem::on_buttonBox_rejected
 */
void deleteitem::on_buttonBox_rejected()
{
    dName = "NONE";
    this->close();
}
