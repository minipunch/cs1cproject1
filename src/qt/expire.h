#ifndef EXPIRE_H
#define EXPIRE_H

#include <QDialog>
#include "Store.h"

namespace Ui {
class expire;
}

class expire : public QDialog
{
    Q_OBJECT

public:
    explicit expire(QWidget *parent = 0);
    string getMonth();
    ~expire();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::expire *ui;
    string month;
};

#endif // EXPIRE_H
