#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QDialog>
#include "executive.h"

namespace Ui {
class DeleteWindow;
}
/*!
 * \brief The DeleteWindow class
 * Structure for deleting a window
 */
class DeleteWindow : public QDialog
{
    Q_OBJECT

public:
    string getDeleteMemberName();
    explicit DeleteWindow(QWidget *parent = 0);
    ~DeleteWindow();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    string deleteMemberName;
    Ui::DeleteWindow *ui;
};

#endif // DELETEWINDOW_H
