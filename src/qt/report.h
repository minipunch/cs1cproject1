#ifndef REPORT_H
#define REPORT_H
#include "Store.h"
#include <QDialog>

namespace Ui {
class Report;
}

class Report : public QDialog
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = 0);
    Date getDate();
    bool getCheq();
    ~Report();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_checkBox_clicked();

private:
    Ui::Report *ui;
    Date date;
    bool cheq;
};

#endif // REPORT_H
