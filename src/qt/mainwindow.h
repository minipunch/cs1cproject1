#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Store.h"
#include <deque>
#include "dialog.h"
#include "deletewindow.h"
#include "mempurchlist.h"
#include "itemnames.h"
#include "additem.h"
#include "deleteitem.h"
#include "report.h"
#include "itemname.h"
#include "expire.h"
namespace Ui {
class MainWindow;
}
/*!
 * \brief Connects the qt UI with a store object
 *
 * This class connects an instance of the store class to the qt ui as well as the other ui classes.
 * See the main page for information on the UI functions of this class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Constructor
     * \param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    /*!
         * \brief destructor
         */
    ~MainWindow();
    //void displayMembers(member mem);
    /*!
     * \brief gets a store object
     *
     * This isn't being used
     * \return store instance
     */
    Store getStore();
    /*!
     * \brief getFilename (not used)
     * \return filename
     */
    string getFilename() const;

private slots:

    void on_pushButton_clicked();
    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

    void on_actionMember_File_Save_triggered();

    void on_actionPurchase_File_Save_triggered();

    void on_actionSave_All_triggered();

    void on_actionMember_File_Import_triggered();

    void on_actionPurchase_File_Import_triggered();

    void on_actionAdd_A_Member_triggered();

    void on_actionDelete_a_member_triggered();

    void on_actionRebate_triggered();

    void on_actionExpirations_triggered();

   // void on_actionSearch_triggered();

    void on_actionNew_triggered();

    void on_actionDelete_triggered();

    void on_actionSearch_2_triggered();

    void on_actionSearch_Member_List_triggered();

    void on_actionAbout_triggered();

    void on_actionInstructions_triggered();

    void on_actionRecommendation_triggered();

private:
    Ui::MainWindow *ui;
    Store bulkClub;
    string filename;
    string filenameI;
    string filenameIS;
    Dialog newMem;
    DeleteWindow deleteMember;
    mempurchList purchList;
    AddItem itemAdd;
    deleteitem itemDel;
    ItemName item;
    Report rep;
    expire exp;


    /*!
     * \file mainwindow.h
     * \brief  Header for main window class
     *
     * This file contains all attributes and private slots for the main window class.
     */
};

#endif // MAINWINDOW_H
