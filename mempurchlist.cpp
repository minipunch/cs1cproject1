#include "mempurchlist.h"
#include "ui_mempurchlist.h"
/*!
 * \brief mempurchList::mempurchList
 * \param parent
 */
mempurchList::mempurchList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mempurchList)
{
    toReturn = "12345";
    ui->setupUi(this);
}
/*!
 * \brief mempurchList::~mempurchList
 */
mempurchList::~mempurchList()
{
    delete ui;
}
/*!
 * \brief mempurchList::getString
 * \return
 */
QString mempurchList::getString() const
{
    return this->toReturn;
}
/*!
 * \brief mempurchList::on_buttonBox_accepted
 */
void mempurchList::on_buttonBox_accepted()
{
    toReturn = this->ui->lineEdit->text();
}
/*!
 * \brief mempurchList::on_buttonBox_rejected
 */
void mempurchList::on_buttonBox_rejected()
{
    toReturn = "None";
}
