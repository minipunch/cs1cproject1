#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"
#include "member.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->filename = "Empty";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->listWidget->clear();

    if(bulkClub.getMemCount() != 0)
    {
        for(int i = 0; i < bulkClub.getMemCount(); i++)
        {
            ui->listWidget->addItem(QString::fromStdString(bulkClub.PrintMember(i)));
        }

    }
    else
    {

        QMessageBox::information(this,tr("Error!"),"You must first import a member file before printing it.");
    }
}
void MainWindow::setDate()
{
    //    Date today;
    //    ui->label_2->setText(QString::fromStdString("Date: " + today.DisplayDate()));
    //
}

Store MainWindow::getStore() {
    return this->bulkClub;
}

//read in members
void MainWindow::on_pushButton_10_clicked()
{

    QString filenameQ = QFileDialog::getOpenFileName(
                this,
                tr("Import members"),
                "C://",
                "Text File (*.txt)"
                );
    this->filename = filenameQ.toStdString();
    this->bulkClub.setFilename(filenameQ.toStdString());

    this->bulkClub.readInMembers();
}

string MainWindow::getFilename() const {
    return this->filename;
}

// PRINT ITEMS
void MainWindow::on_pushButton_8_clicked()
{
    ui->listWidget->clear();
    double tot = 0;
    double totW = 0;
    bulkClub.sortingItems(ID);

    if(this->filenameI == "Empty")
    {
        QMessageBox::information(this,tr("Error!"),"You must first import a purchase file before printing it.");
    }
    else if(this->filenameI == "")
    {
        QMessageBox::information(this,tr("Error!"),"You must first import a purchase file before printing it.");
    }
    else
    {

        for(int i = 0; i < bulkClub.getItemCount(); i++)
        {
            ui->listWidget->addItem(QString::fromStdString(bulkClub.PrintItem(i)));
            tot = tot + bulkClub.getTotCost(i);
            totW = totW + bulkClub.getTotwTax(i);
        }


        ui->listWidget->addItem("Total Cost(Pre-tax)   : $" + QString::number(tot, 'f', 2));
        ui->listWidget->addItem("Total Cost(Post-tax) : $" + QString::number(totW, 'f', 2));


    }
}
// SELECT AND IMPORT ITEM FILE
void MainWindow::on_pushButton_11_clicked()
{
    if(bulkClub.getMemCount() !=0)
    {
        QString filenameQ = QFileDialog::getOpenFileName(
                    this,
                    tr("Import a purchase file"),
                    "C://",
                    "Text File (*.txt)"
                    );
        this->filenameI = filenameQ.toStdString();
        this->bulkClub.setFilenameI(filenameQ.toStdString());

        this->bulkClub.readItems();
    }
    else
    {
        QMessageBox::information(this,tr("Error!"),"Member database empty, please import a member list first.");
    }
}

// ADD A NEW MEMBER
void MainWindow::on_addmem_clicked()
{

    newMem.exec();

    member *addPtr = newMem.GetNewMem();
    if(addPtr != NULL)
    {
        bulkClub.addMember(addPtr);
    }
    else
    {
        QMessageBox::information(this,tr("Action Cancelled!"),"No Members added.");
    }
    bulkClub.sortingMems(NAME);

}

// SAVE MEMBER FILE
void MainWindow::on_pushButton_12_clicked()
{
    if(bulkClub.getMemCount() !=0)
    {
        bulkClub.saveMembers();
        QMessageBox::information(this,tr("List Saved!"),"Your members list has been saved.");
    }
    else
    {
        QMessageBox::information(this,tr("Error!"),"Member database empty. Please import a member list first.");
    }
}

// DELETE A MEMBER
void MainWindow::on_pushButton_7_clicked()
{

    if(bulkClub.getMemCount() !=0)
    {
        deleteMember.exec();
        string nameDel = deleteMember.getDeleteMemberName();
        if(nameDel == "None")
        {
            QMessageBox::information(this,tr("Error!"),"Delete Cancelled");
        }
        else
        {
            // grab proper index location to delete from the <deque> of member pointers.
            int deleteIndex = bulkClub.getMemberIndex(nameDel);

            if(deleteIndex < bulkClub.getMemCount())
            {
                QMessageBox::information(this,tr("Done."),"Member has been removed");
                bulkClub.removeMember(deleteIndex);

            }
            else
            {
                QMessageBox::information(this,tr("Error!"),"Member not found within the database");
            }

        }
    }
    else
    {
        QMessageBox::information(this,tr("Error!"),"Member database empty. No members to Delete.");
    }


}
//save purchases
void MainWindow::on_pushButton_13_clicked()
{

    if(bulkClub.getItemCount() !=0)
    {
        QString filenameQ = QFileDialog::getOpenFileName(
                    this,
                    tr("Import a purchase file"),
                    "C://",
                    "Text File (*.txt)"
                    );
        this->filenameIS = filenameQ.toStdString();
        this->bulkClub.setFilenameIS(filenameQ.toStdString());
        this->bulkClub.saveItems();
    }
    else
    {
         QMessageBox::information(this,tr("Error!"),"No Items to save.");
    }
}
//number 7
void MainWindow::on_pushButton_6_clicked()
{
   if(bulkClub.getMemCount() !=0)
   {
       if(bulkClub.getItemCount() !=0)
       {
           double id;
           int index;
           string name;
           purchList.exec();
           QString temp = purchList.getString();
           bulkClub.sortingItems(NAME);
           if(temp == "None")
           {
                QMessageBox::information(this,tr("Error!"),"Action Cancelled");
           }
           else
           {
               QString temp2 = temp.left(1);
               if(temp2 == "1" || temp2 == "2" || temp2 == "3" || temp2 == "4"
               || temp2 == "5" || temp2 == "6" || temp2 == "7" || temp2 == "8" || temp2 == "9")
               {
                     id = temp.toDouble();


                     ui->listWidget->clear();
                     for( int i = 0; i < bulkClub.getItemCount(); i++)
                     {
                         if(bulkClub.getiID(i) == id)
                         {
                              ui->listWidget->addItem(QString::fromStdString(bulkClub.PrintItem(i)));
                         }
                     }
               }
               else
               {
                    name = temp.toStdString();
                    index = bulkClub.getMemberIndex(name);
                    if(index < bulkClub.getMemCount())
                    {
                         id = bulkClub.getMemID(index);
                         ui->listWidget->clear();
                         for( int i = 0; i < bulkClub.getItemCount(); i++)
                         {
                             if(bulkClub.getiID(i) == id)
                             {
                                  ui->listWidget->addItem(QString::fromStdString(bulkClub.PrintItem(i)));
                             }
                         }

                    }
                    else
                    {
                         QMessageBox::information(this,tr("Error!"),"Person not found. ");
                    }

               }

           }
       }
       else
       {
             QMessageBox::information(this,tr("Error!"),"No Items to show!");
       }

   }
   else
   {
         QMessageBox::information(this,tr("Error!"),"Member database empty");
   }
}

void MainWindow::on_pushButton_15_clicked()
{

    if(bulkClub.getMemCount() != 0)
    {
        itemAdd.exec();
            Item *addPtr = itemAdd.GetItem();
            if(addPtr != NULL)
            {
                bulkClub.addItem(addPtr);
            }
            else
            {
                QMessageBox::information(this,tr("Action Cancelled!"),"No Items added.");
            }
            bulkClub.sortingItems(NAME);
    }
    else
    {
        QMessageBox::information(this,tr("No Members!"),"Please add members to the database first.");
    }
}


void MainWindow::on_pushButton_16_clicked()
{
    string name;

        if(bulkClub.getMemCount() != 0)
        {
            itemDel.exec();
                name = itemDel.delItem();
                if(name != "NONE")
                {
                    bulkClub.delItem(name);
                }
                else
                {
                    QMessageBox::information(this,tr("Action Cancelled!"),"Item name not found/not specified.");
                }
                bulkClub.sortingItems(NAME);
        }
        else
        {
            QMessageBox::information(this,tr("No Members!"),"Please add members to the database first.");
        }
}

void MainWindow::on_pushButton_2_clicked()
{
    int q = 0;
    float t = 0;
    item.exec();
    string iname;
    iname = item.getItem();
    if(bulkClub.getMemCount() != 0)
    {
        if(iname.empty() == false){
          ui->listWidget->clear();

            for(int i = 0; i < bulkClub.getItemCount();i++){
                if(bulkClub.getiName(i) == iname){
                    t += bulkClub.getTotwTax(i);
                    q += bulkClub.getiQuan(i);
                }
            }
            ui->listWidget->addItem("Information on item: " +QString::fromStdString(iname));
            ui->listWidget->addItem("Quantity   : " + QString::number(q));
            ui->listWidget->addItem("Total Cost(Post-tax) : $" + QString::number(t, 'f', 2));
        }
        else{

            QMessageBox::information(this,tr("Error"),"Item not found or specified.");

        }
        bulkClub.sortingItems(NAME);
    }
    else
    {
        QMessageBox::information(this,tr("No Members!"),"Please add members to the database first.");
    }
}
void MainWindow::on_pushButton_5_clicked()
{
    ui->listWidget->clear();
    for(int count = 0; count < bulkClub.getMemCount();count++)
    {
        if(bulkClub.getMemType(count) == "Executive"){
            ui->listWidget->addItem(QString::fromStdString(bulkClub.getMemName(count)));
            ui->listWidget->addItem("Rebate: " + QString::fromStdString(bulkClub.getRebate(count)));
        }
    }
    bulkClub.sortingMems(ID);
}

void MainWindow::on_pushButton_3_clicked()
{
    int totalRevenue = 0;
    int totalQuantity = 0;
    bool theSame = true;

    ui->listWidget->clear();
    bulkClub.sortingItems(NAME);


    if(bulkClub.getItemCount() != 0)
    // ... make sure user has input a purchase file before scanning through list
    {
        for(int x = 0; x < bulkClub.getItemCount() - 1; ++x)
        {
            // for each item
            totalRevenue = 0;
            totalQuantity = 0;
            theSame = true;

            // print item name
            ui->listWidget->addItem("Information on item: " +QString::fromStdString(bulkClub.getiName(x)));

            if(x < bulkClub.getItemCount() - 1)
            // ... if not at the last item in the list ...
            {
                while((bulkClub.getiName(x) == bulkClub.getiName(x+1)) && theSame == true)
                // ... for each item WITH THE SAME NAME (duplicates)
                {

                    if(bulkClub.getiName(x)!= bulkClub.getiName(x+1))
                    {
                        theSame = false;
                    }

                    totalQuantity += bulkClub.getiQuan(x);
                    totalRevenue  += bulkClub.getTotwTax(x);

                    x++;

                }
                totalQuantity += bulkClub.getiQuan(x);
                totalRevenue  += bulkClub.getTotwTax(x);
            }
            // Quantity for each item
            ui->listWidget->addItem("Quantity: " + QString::number(totalQuantity));
            // Total revenue for each item
            ui->listWidget->addItem("Total Revenue: $" + QString::number(totalRevenue, 'f', 2));
        }

        // ghetto solution to the diet coke problem
        totalQuantity = 0;
        totalRevenue = 0;

        totalQuantity += bulkClub.getiQuan(bulkClub.getItemCount() - 1);
        totalRevenue  += bulkClub.getTotwTax(bulkClub.getItemCount() - 1);

        // print item name
        ui->listWidget->addItem("Information on item: " +QString::fromStdString(bulkClub.getiName(bulkClub.getItemCount() - 1)));
        // Quantity for each item
        ui->listWidget->addItem("Quantity: " + QString::number(totalQuantity));
        // Total revenue for each item
        ui->listWidget->addItem("Total Revenue: $" + QString::number(totalRevenue, 'f', 2));
        ui->listWidget->addItem(" ");
    }
    else {
      QMessageBox::information(this,tr("No purchase file seleceted!"),"Please import one or more purchase files in order to continue.");
    }



}
void MainWindow::on_pushButton_clicked()
{
    Date d;
    rep.exec();
//    deque <Item*> stuff;
    d = rep.getDate();
    deque<string> names;
    int nameDup = 0;
    int exec = 0;
    int reg = 0;

    for (int i = 0; i < bulkClub.getItemCount(); i++){
//        names.push_back(bulkClub.getName(i));
        if(bulkClub.getiDate(i) == d){
            string memName = bulkClub.getMemName(i);
            ui->listWidget->addItem(QString::fromStdString(bulkClub.getiName(i)));
            ui->listWidget->addItem(QString::number(bulkClub.getiQuan(i)));
//            if(names.empty() == false){
//                for(int z = 0; z < names.size(); z++){
//                    if(names.at(z) == memName){
//                        nameDup++;
//                    }
//                }
//                if(nameDup == 0){
//                    names.push_back(memName);
//                }
//                else{
//                    nameDup = 0;
//                }
//            }
//            else{
//                names.push_back(memName);
//            }

        }
    }
//    for(int i = 0; i < names.size(); i++){
//        if(bulkClub.getMemType(bulkClub.getMemberIndex(names.at(i))) == "Executive"){
//            exec++;
//        }
//        else{
//            reg++;
//        }
//    }
//    for(int i = 0; i < names.size();i++){
//        ui->listWidget->addItem(QString::fromStdString(names.at(i)));
//    }
//    ui->listWidget->addItem("Executive: "+ QString::number(exec));


}

//        if(bulkClub.getiName(x) != bulkClub.getiName(x+1))
//        {
//            for(int i = 0; i < (x+1); i++){
//             if(bulkClub.getiName(i) == bulkClub.getiName(x)){
//                 totalRevenue += bulkClub.getTotwTax(i);
//                 totalQuantity += bulkClub.getiQuan(i);
//                }
//             }
//            ui->listWidget->addItem("Information on item: " +QString::fromStdString(bulkClub.getiName(x)));
//            ui->listWidget->addItem("Quantity   : " + QString::number(totalQuantity));
//            ui->listWidget->addItem("Total Cost(Post-tax) : $" + QString::number(totalRevenue, 'f', 2));
//        }
