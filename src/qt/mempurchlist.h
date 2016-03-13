#ifndef MEMPURCHLIST_H
#define MEMPURCHLIST_H

#include <QDialog>

namespace Ui {
class mempurchList;
}

class mempurchList : public QDialog
{
    Q_OBJECT

public:
    explicit mempurchList(QWidget *parent = 0);
    ~mempurchList();
    QString getString() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::mempurchList *ui;
    QString toReturn;
};

#endif // MEMPURCHLIST_H
