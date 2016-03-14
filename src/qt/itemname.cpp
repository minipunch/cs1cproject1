#include "itemname.h"
#include "ui_itemname.h"
#include "Store.h"

ItemName::ItemName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemName)
{
    ui->setupUi(this);
}

ItemName::~ItemName()
{
    delete ui;
}

void ItemName::on_buttonBox_accepted()
{
    // grab text from the line edit field
    QString nameQ = this->ui->name->text();
    // convert to STD string
    string name1 = nameQ.toStdString();
    name = name1;
}
string ItemName::getItem(){
    return name;
}

void ItemName::on_buttonBox_rejected()
{
    this->close();
}
