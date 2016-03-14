#ifndef DELETEITEM_H
#define DELETEITEM_H

#include <QDialog>
#include "Store.h"

namespace Ui {
class deleteitem;
}

class deleteitem : public QDialog
{
    Q_OBJECT

public:
    explicit deleteitem(QWidget *parent = 0);
    string delItem();
    ~deleteitem();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::deleteitem *ui;
    string dName;
};

#endif // DELETEITEM_H
