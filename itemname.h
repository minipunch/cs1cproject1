#ifndef ITEMNAME_H
#define ITEMNAME_H
#include "Store.h"
#include <QDialog>

namespace Ui {
class ItemName;
}
/*!
 * \brief The ItemName class
 *  Manages naming an item
 *
 */
class ItemName : public QDialog
{
    Q_OBJECT

public:
    explicit ItemName(QWidget *parent = 0);
    string getItem();
    ~ItemName();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ItemName *ui;
    string name;
};

#endif // ITEMNAME_H
