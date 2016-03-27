#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.cpp"
#include "member.h"
#include <QMessageBox>
#include <QFileDialog>

/*!
 * \file mainwindow.cpp
 * \brief Source file for mainwindow class methods
 *
 * This file contains all of the definitions for the mainwindow class
 */
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->filename = "Empty";
    this->ui->menuFile->setStyleSheet("background-color: orange;");

}

MainWindow::~MainWindow() {
    delete ui;
}

// show all members
// Shows all registered members
void MainWindow::on_pushButton_9_clicked() {
    ui->listWidget->clear();

    if (bulkClub.getMemCount() != 0) {
        for (int i = 0; i < bulkClub.getMemCount(); i++) {
            ui->listWidget->addItem(
                    QString::fromStdString(bulkClub.PrintMember(i)));
        }

    } else {

        QMessageBox::information(this, tr("Error!"),
                "You must first import a member file before printing it.");
    }
}

Store MainWindow::getStore() {
    return this->bulkClub;
}



string MainWindow::getFilename() const {
    return this->filename;
}

// Shows all items bought at the store
void MainWindow::on_pushButton_8_clicked() {


    if(bulkClub.getItemCount() !=0)
    {
        ui->listWidget->clear();
        double tot = 0;
        double totW = 0;
        bulkClub.sortingItems(ID);
        for (int i = 0; i < bulkClub.getItemCount(); i++) {
            ui->listWidget->addItem(
                    QString::fromStdString(bulkClub.PrintItem(i)));
            tot = tot + bulkClub.getTotCost(i);
            totW = totW + bulkClub.getTotwTax(i);
        }

        ui->listWidget->addItem("Total Cost(Pre-tax)   : $" + QString::number(tot, 'f', 2));
        ui->listWidget->addItem("Total Cost(Post-tax) : $" + QString::number(totW, 'f', 2));
    }
    else
    {
        QMessageBox::information(this, tr("Error!"),
                "You must add items before printing them.");
    }





//    if (this->filenameI == "Empty") {
//        QMessageBox::information(this, tr("Error!"),
//                "You must first import a purchase file before printing it.");
//    } else if (this->filenameI == "") {
//        QMessageBox::information(this, tr("Error!"),
//                "You must first import a purchase file before printing it.");
//    } else {



//    }
}

//number 3 total quantity and cost of each item
//Gives the total quantity and revenue for each item bought
void MainWindow::on_pushButton_3_clicked() {
    int totalRevenue = 0;
    int totalQuantity = 0;
    bool theSame = true;


    if (bulkClub.getItemCount() != 0)


    // ... make sure user has input a purchase file before scanning through list
            {
        ui->listWidget->clear();
        bulkClub.sortingItems(NAME);

        for (int x = 0; x < bulkClub.getItemCount() - 1; ++x) {
            // for each item
            totalRevenue = 0;
            totalQuantity = 0;
            theSame = true;

            // print item name
            ui->listWidget->addItem(
                    "Information on item: "
                            + QString::fromStdString(bulkClub.getiName(x)));

            if (x < bulkClub.getItemCount() - 1)
            // ... if not at the last item in the list ...
                    {
                while ((bulkClub.getiName(x) == bulkClub.getiName(x + 1))
                        && theSame == true)
                // ... for each item WITH THE SAME NAME (duplicates)
                {

                    if (bulkClub.getiName(x) != bulkClub.getiName(x + 1)) {
                        theSame = false;
                    }

                    totalQuantity += bulkClub.getiQuan(x);
                    totalRevenue += bulkClub.getTotwTax(x);

                    x++;

                }
                totalQuantity += bulkClub.getiQuan(x);
                totalRevenue += bulkClub.getTotwTax(x);
            }
            // Quantity for each item
            ui->listWidget->addItem(
                    "Quantity: " + QString::number(totalQuantity));
            // Total revenue for each item
            ui->listWidget->addItem(
                    "Total Revenue: $" + QString::number(totalRevenue, 'f', 2));
        }

        // ghetto solution to the diet coke problem
        totalQuantity = 0;
        totalRevenue = 0;

        totalQuantity += bulkClub.getiQuan(bulkClub.getItemCount() - 1);
        totalRevenue += bulkClub.getTotwTax(bulkClub.getItemCount() - 1);

        // print item name
        ui->listWidget->addItem(
                "Information on item: "
                        + QString::fromStdString(
                                bulkClub.getiName(
                                        bulkClub.getItemCount() - 1)));
        // Quantity for each item
        ui->listWidget->addItem("Quantity: " + QString::number(totalQuantity));
        // Total revenue for each item
        ui->listWidget->addItem(
                "Total Revenue: $" + QString::number(totalRevenue, 'f', 2));
        ui->listWidget->addItem(" ");
    } else {
        QMessageBox::information(this, tr("No purchase file seleceted!"),
                "Please import one or more purchase files in order to continue.");
    }

}
//number 1: sales report
//Prints sales report
void MainWindow::on_pushButton_clicked() {
    Date d;
    Date d2;

    if(bulkClub.getItemCount() !=0)
    {
        rep.exec();
        d = rep.getDate();
        if(d.GetYear() != 1900)
        {
            ui->listWidget->clear();
            ui->listWidget->addItem(QString::fromStdString(d.DisplayDate()));

            deque < string > names;
            int nameDup = 0;
            int exec = 0;
            int reg = 0;
            for (int i = 0; i < bulkClub.getItemCount(); i++) {
                d2 = bulkClub.getiDate(i);
                if (d2 == d) {
                    double memID = bulkClub.getiID(i);
                    string memName = bulkClub.getMemName(bulkClub.searchMem(memID));
                    ui->listWidget->addItem(
                            QString::fromStdString(bulkClub.getiName(i)));
                    ui->listWidget->addItem(
                            "Quantity: " + QString::number(bulkClub.getiQuan(i)));
                    if (names.empty() == false) {
                        for (unsigned int z = 0; z < names.size(); z++) {
                            if (names.at(z) == memName) {
                                nameDup++;
                            }
                        }
                        if (nameDup == 0) {
                            names.push_back(memName);
                        } else {
                            nameDup = 0;
                        }
                    } else {
                        names.push_back(memName);
                    }

                }
            }
            if(rep.getCheq() != true){
                for (unsigned int i = 0; i < names.size(); i++) {
                    if (bulkClub.getMemType(bulkClub.getMemberIndex(names.at(i)))
                            == "Executive") {
                        ui->listWidget->addItem(
                                QString::fromStdString(names.at(i)) + "\nType: Executive");
                        exec++;
                    } else {
                        ui->listWidget->addItem(
                                QString::fromStdString(names.at(i)) + "\nType: Regular");
                        reg++;
                    }
                }
            }
            else{
                for (unsigned int i = 0; i < names.size(); i++) {
                    if (bulkClub.getMemType(bulkClub.getMemberIndex(names.at(i)))
                            == "Executive") {
                        ui->listWidget->addItem(
                                QString::fromStdString(names.at(i)) + "\nType: Executive");
                        exec++;
                    }
                }
                for (unsigned int i = 0; i < names.size(); i++) {
                    if (bulkClub.getMemType(bulkClub.getMemberIndex(names.at(i)))
                            == "Regular") {
                        ui->listWidget->addItem(
                                QString::fromStdString(names.at(i)) + "\nType: Regular");
                        reg++;
                    }
                }
            }
            ui->listWidget->addItem("Executive: " + QString::number(exec));
            ui->listWidget->addItem("Regular: " + QString::number(reg));

        }
        else
        {
            QMessageBox::information(this, tr("Cancelled!"),
                    "Action Cancelled");
        }

    }
    else
    {
        QMessageBox::information(this, tr("Error!"), "No purchases in the database, please import purchase file(s).");
    }

}


// save member file
// Saves the member list in its current state to the original file.
void MainWindow::on_actionMember_File_Save_triggered()
{
    if (bulkClub.getMemCount() != 0) {
        bulkClub.saveMembers();
        QMessageBox::information(this, tr("List Saved!"),
                "Your members list has been saved.");
    } else {
        QMessageBox::information(this, tr("Error!"),
                "Member database empty. Please import a member list first.");
    }
}
//save items
//browse and select a file to save to and the purchase list will be saved there.
void MainWindow::on_actionPurchase_File_Save_triggered()
{

    if (bulkClub.getItemCount() != 0) {
        QString filenameQ = QFileDialog::getOpenFileName(this,
                tr("Import a purchase file"), "C://", "Text File (*.txt)");
        this->filenameIS = filenameQ.toStdString();
        this->bulkClub.setFilenameIS(filenameQ.toStdString());
        this->bulkClub.saveItems();
    } else {
        QMessageBox::information(this, tr("Error!"), "No Items to save.");
    }
}

// save member file and purchase/item file
//Save both files at once
void MainWindow::on_actionSave_All_triggered()
{
    // ... first save members
    if (bulkClub.getMemCount() != 0) {
        bulkClub.saveMembers();
        QMessageBox::information(this, tr("List Saved!"),
                "Your members list has been saved.");
    } else {
        QMessageBox::information(this, tr("Error!"),
                "Member database empty. Please import a member list first.");
    }

    // ... then save items
    if (bulkClub.getItemCount() != 0) {
        QString filenameQ = QFileDialog::getOpenFileName(this,
                tr("Import a purchase file"), "C://", "Text File (*.txt)");
        this->filenameIS = filenameQ.toStdString();
        this->bulkClub.setFilenameIS(filenameQ.toStdString());
        this->bulkClub.saveItems();
    } else {
        QMessageBox::information(this, tr("Error!"), "No Items to save.");
    }
}

// import member file
//browse and select a member file and the members will be added to the member list.
void MainWindow::on_actionMember_File_Import_triggered()
{
    QString filenameQ = QFileDialog::getOpenFileName(this, tr("Import members"),
            "C://", "Text File (*.txt)");
    this->filename = filenameQ.toStdString();
    this->bulkClub.setFilename(filenameQ.toStdString());

    this->bulkClub.readInMembers();
}

// import purchase/item file
//browse and select a purchase file and the items will be added to the item list and their prices will be applied to the right members.
void MainWindow::on_actionPurchase_File_Import_triggered()
{
    if (bulkClub.getMemCount() != 0) {
        QString filenameQ = QFileDialog::getOpenFileName(this,
                tr("Import a purchase file"), "C://", "Text File (*.txt)");
        this->filenameI = filenameQ.toStdString();
        this->bulkClub.setFilenameI(filenameQ.toStdString());

        this->bulkClub.readItems();
    } else {
        QMessageBox::information(this, tr("Error!"),
                "Member database empty, please import a member list first.");
    }
}

// add a new member
void MainWindow::on_actionAdd_A_Member_triggered()
{
    int index;

    newMem.exec();

    member *addPtr = newMem.GetNewMem();
    if (addPtr != NULL) {

        index = bulkClub.searchMem(addPtr->getId());
        if (index < bulkClub.getMemCount()) {
            QMessageBox::information(this, tr("Error!"),
                    "Duplicate id number found, please enter another.");
        } else {
            bulkClub.addMember(addPtr);
        }

    } else {
        QMessageBox::information(this, tr("Action Cancelled!"),
                "No Members added.");
    }
    bulkClub.sortingMems(NAME);
}

// delete a member
void MainWindow::on_actionDelete_a_member_triggered()
{
    if (bulkClub.getMemCount() != 0) {
        bulkClub.sortingItems(NAME);
        deleteMember.exec();
        string nameDel = deleteMember.getDeleteMemberName();
        if (nameDel == "None") {
            QMessageBox::information(this, tr("Error!"), "Delete Cancelled");
        } else {
            // grab proper index location to delete from the <deque> of member pointers.
            int deleteIndex = bulkClub.getMemberIndex(nameDel);

            if (deleteIndex < bulkClub.getMemCount()) {
                QMessageBox::information(this, tr("Done."),
                        "Member has been removed");
                double did = bulkClub.getMemID(deleteIndex);

                for(int i = 0; i < bulkClub.getItemCount();i++){
                    if (bulkClub.getiID(i) == did){
                        bulkClub.removeItem(i);
                    }
                }

                //double did = bulkClub.getMemID(deleteIndex);

                for(int i = 0; i < bulkClub.getItemCount();i++){
                    if (bulkClub.getiID(i) == did){
                        bulkClub.removeItem(i);
                    }
                }
                bulkClub.removeMember(deleteIndex);


            } else {
                QMessageBox::information(this, tr("Error!"),
                        "Member not found within the database");
            }

        }
    } else {
        QMessageBox::information(this, tr("Error!"),
                "Member database empty. No members to Delete.");
    }
}

// show rebates
//Show the rebates of all executive members
void MainWindow::on_actionRebate_triggered()
{
    if(bulkClub.getMemCount() != 0)
    {
        ui->listWidget->clear();
        for (int count = 0; count < bulkClub.getMemCount(); count++) {
            if (bulkClub.getMemType(count) == "Executive") {
                ui->listWidget->addItem(
                        QString::fromStdString(bulkClub.getMemName(count)));
                ui->listWidget->addItem(
                        "Rebate: "
                                + QString::fromStdString(
                                        bulkClub.getRebate(count)));
            }
        }
        bulkClub.sortingMems(ID);
    }
    else
    {
        QMessageBox::information(this, tr("Error!"),
                "Member database empty, please add members first.");
    }
}


// see membership expirations
//Input a month and get all memberships that expire that month and their renewal cost
void MainWindow::on_actionExpirations_triggered()
{
    if(bulkClub.getMemCount() != 0)
    {
        exp.exec();
        string mon = exp.getMonth();
        ui->listWidget->clear();
        int month;
        int cheq = 0;
        bool m0n;

        if (mon == "None") {
            QMessageBox::information(this, tr("Error!"), "Action Cancelled");
        } else {
            QString tem = QString::fromStdString(mon);
            month = tem.toInt(&m0n);
            if (!m0n) {
                QString month2 = QString::fromStdString(mon);
                month2 = month2.toLower();
                mon = month2.toStdString();
                if (mon == "january") {
                    month = 1;
                } else if ("february" == mon) {
                    month = 2;
                } else if ("march" == mon) {
                    month = 3;
                } else if ("april" == mon) {
                    month = 4;
                } else if ("may" == mon) {
                    month = 5;
                } else if ("june" == mon) {
                    month = 6;
                } else if ("july" == mon) {
                    month = 7;
                } else if ("august" == mon) {
                    month = 8;
                } else if ("september" == mon) {
                    month = 9;
                } else if ("october" == mon) {
                    month = 10;
                } else if ("november" == mon) {
                    month = 11;
                } else if ("december" == mon) {
                    month = 12;
                }
            }

        }
        for (int i = 0; i < bulkClub.getMemCount(); i++) {
            if (bulkClub.getMemExp(i).GetMonth() == month) {
                ui->listWidget->addItem(
                        QString::fromStdString(bulkClub.PrintMember(i)));
                        cheq++;
                if (bulkClub.getMemType(i) == "Executive") {
                    ui->listWidget->addItem("Annual Membership Fee Cost: $125\n");
                } else {
                    ui->listWidget->addItem("Annual Membership Fee Cost: $45\n");
                }
            }
        }
        if(cheq == 0){
            ui->listWidget->addItem("No ones membership expires during that month.\n");
        }
    }
    else
    {
        QMessageBox::information(this, tr("Error!"),
                "Member database empty, please add members first.");
    }

}


// new product
void MainWindow::on_actionNew_triggered()
{
    if (bulkClub.getMemCount() != 0) {
        itemAdd.exec();
        Item *addPtr = itemAdd.GetItem();
        if (addPtr != NULL) {
            bulkClub.addItem(addPtr);
        } else {
            QMessageBox::information(this, tr("Action Cancelled!"),
                    "No Items added.");
        }
        bulkClub.sortingItems(NAME);
    } else {
        QMessageBox::information(this, tr("No Members!"),
                "Please add members before continuing.");
    }
}

// delete product
void MainWindow::on_actionDelete_triggered()
{
    string name;

    if (bulkClub.getMemCount() != 0) {
        itemDel.exec();
        name = itemDel.delItem();
        if (name != "NONE") {
            bulkClub.delItem(name);
        } else {
            QMessageBox::information(this, tr("Action Cancelled!"),
                    "Item name not found/not specified.");
        }
        bulkClub.sortingItems(NAME);
    } else {
        QMessageBox::information(this, tr("No purchase/item list found!"),
                "Please import a purchase/item file before continuing.");
    }
}

// search for product
void MainWindow::on_actionSearch_2_triggered()
{
    int q = 0;
    float t = 0;

    if (bulkClub.getItemCount() != 0) {

        item.exec();
        string iname;
        iname = item.getItem();
        if (iname != "None") {
            ui->listWidget->clear();

            for (int i = 0; i < bulkClub.getItemCount(); i++) {
                if (bulkClub.getiName(i) == iname) {
                    t += bulkClub.getTotwTax(i);
                    q += bulkClub.getiQuan(i);
                }
            }
            ui->listWidget->addItem(
                    "Information on item: " + QString::fromStdString(iname));
            ui->listWidget->addItem("Quantity   : " + QString::number(q));
            ui->listWidget->addItem(
                    "Total Cost(Post-tax) : $" + QString::number(t, 'f', 2));
        } else {

            QMessageBox::information(this, tr("Error"),
                    "Item not found or specified.");

        }
        bulkClub.sortingItems(NAME);
    } else {
        QMessageBox::information(this, tr("No purchase/item list found!"),
                "Please import a purchase/item file before continuing.");
    }
}
//search the member list
void MainWindow::on_actionSearch_Member_List_triggered()
{
    if (bulkClub.getMemCount() != 0) {
          if (bulkClub.getItemCount() != 0) {
              double id;
              int index;
              string name;
              purchList.exec();
              QString temp = purchList.getString();
              bulkClub.sortingItems(NAME);
              if (temp == "None") {
                  QMessageBox::information(this, tr("Error!"),
                          "Action Cancelled");
              } else {
                  QString temp2 = temp.left(1);
                  if (temp2 == "1" || temp2 == "2" || temp2 == "3" || temp2 == "4"
                          || temp2 == "5" || temp2 == "6" || temp2 == "7"
                          || temp2 == "8" || temp2 == "9") {
                      id = temp.toDouble();

                      ui->listWidget->clear();
                      for (int i = 0; i < bulkClub.getItemCount(); i++) {
                          if (bulkClub.getiID(i) == id) {
                              ui->listWidget->addItem(
                                      QString::fromStdString(
                                              bulkClub.PrintItem(i)));
                          }
                      }
                  } else {
                      name = temp.toStdString();
                      index = bulkClub.getMemberIndex(name);
                      if (index < bulkClub.getMemCount()) {
                          id = bulkClub.getMemID(index);
                          ui->listWidget->clear();
                          for (int i = 0; i < bulkClub.getItemCount(); i++) {
                              if (bulkClub.getiID(i) == id) {
                                  ui->listWidget->addItem(
                                          QString::fromStdString(
                                                  bulkClub.PrintItem(i)));
                              }
                          }

                      } else {
                          QMessageBox::information(this, tr("Error!"),
                                  "Person not found. ");
                      }

                  }

              }
          } else {
              QMessageBox::information(this, tr("Error!"), "No Items to show!");
          }

      } else {
          QMessageBox::information(this, tr("Error!"), "Member database empty");
      }
}
//Displays basic info about the project.
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, tr("Team Five GUI's"), "Team Five GUI's:\nChris Bassar\nDallas Wendt\nDustin Vuong\nJosh Yolles\nNick Sidaris\n\nAll rights reserved. Plagerizers will be prosecuted.");
}
//Displays basic Instructions on using the program.
void MainWindow::on_actionInstructions_triggered()
{
    QMessageBox::information(this, tr("Team Five GUI's Bulk Club Manager"), "How to use\n\nStep 1: Import a valid list of shoppers\nStep 2: Import a purchase file\nStep 3: Run any Commands you wish\nStep 4(optional): Save your member and/or purchase list.");
}
//Show which members would save money by changing their membership type.
void MainWindow::on_actionRecommendation_triggered()
{
    if(bulkClub.getMemCount() != 0)
    {
        ui->listWidget->clear();
            double compare;
            bulkClub.sortingMems(ID);
            for(int i = 0; i < bulkClub.getMemCount();i++){
                compare = bulkClub.getMTotCost(i) * .035;
                if(bulkClub.getMemType(i) == "Regular"){
                    if(compare > 80){
                        ui->listWidget->addItem(QString::fromStdString(bulkClub.getMemName(i) + "\n"));
                        ui->listWidget->addItem(QString::fromStdString(bulkClub.getMemType(i) + "\n"));
                        ui->listWidget->addItem("Upgrade Recommended\n");
                        ui->listWidget->addItem("Amount Saved: $" + QString::number((45 - (125- compare)),'f',2) + "\n");
                    }
                }
            }
            for(int i = 0; i < bulkClub.getMemCount();i++){
                compare = bulkClub.getMTotCost(i) * .035;
                if(bulkClub.getMemType(i) == "Regular"){
                    if(compare < 80){
                        ui->listWidget->addItem(QString::fromStdString(bulkClub.getMemName(i) + "\n"));
                        ui->listWidget->addItem(QString::fromStdString(bulkClub.getMemType(i) + "\n"));
                        ui->listWidget->addItem("Downgrade Recommended\n");

                        ui->listWidget->addItem("Amount Saved: $" + QString::number(((125-compare) - 45),'f',2) + "\n");
                    }
                }
            }
    }
    else
    {
         QMessageBox::information(this, tr("Error!"), "Member database empty");
    }

}
