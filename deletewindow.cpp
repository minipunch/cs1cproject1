#include "deletewindow.h"
#include "ui_deletewindow.h"
/*!
 * \brief DeleteWindow::DeleteWindow
 * \param parent
 */
DeleteWindow::DeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteWindow)
{
    deleteMemberName = "None";
    ui->setupUi(this);
}
/*!
 * \brief DeleteWindow::~DeleteWindow
 */
DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::on_buttonBox_accepted()
{
    // grab text from the line edit field
    QString nameQ = this->ui->lineEdit->text();
    // convert to STD string
    string name = nameQ.toStdString();
    // set private date member for DeleteWindow class. For use in the MainWindow button.
    this->deleteMemberName = name;

}
/*!
 * \brief DeleteWindow::getDeleteMemberName
 * \return
 */
string DeleteWindow::getDeleteMemberName() {
    return this->deleteMemberName;
}

// CANCEL BUTTON
/*!
 * \brief DeleteWindow::on_buttonBox_rejected
 */
void DeleteWindow::on_buttonBox_rejected()
{
    deleteMemberName = "None";
    this->close();
}
