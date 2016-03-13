#ifndef AddItem_H
#define AddItem_H

#include <QDialog>
#include "Store.h"

namespace Ui {
class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddItem(QWidget *parent = 0);
    Item* GetItem();
    ~AddItem();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddItem *ui;
    Item *dItem;

};

#endif // AddItem_H
