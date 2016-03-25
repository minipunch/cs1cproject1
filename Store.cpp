/*
 * Store.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Nick
 */

#include "Store.h"
#include "member.cpp"
#include "executive.cpp"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include<QByteArray>
/*!
 * \brief Store::Store
 */
Store::Store() {


	// TODO Auto-generated constructor stub

}
/*!
 * \brief Store::~Store
 */
Store::~Store() {
	//cout << "test" << endl;
	// TODO Auto-generated destructor stub
}
/*!
 * \brief Store::ConvertDate
 * \param dateIn
 * \return
 */
Date Store::ConvertDate(string dateIn)
{
	Date temp;
	string pt1 = dateIn.substr(0,2);
	string pt2 = dateIn.substr(3,2);
	string pt3 = dateIn.substr(6);
	unsigned int month = atoi(pt1.c_str());
	unsigned int day = atoi(pt2.c_str());
	unsigned int year = atoi(pt3.c_str());
	temp.SetDate(month, day, year);
	return temp;
}

/*!
 * \brief Store::readInMembers
 */
void Store::readInMembers()
{
    this->members.clear();

    QString fName = QString::fromStdString(this->filename);
    QFile file(fName);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"Member Read Error",file.errorString());

    QTextStream in(&file);
        QString name;
        string nameStr;
        QString type;
        string typeStr;
        double idNum;
        QString idNumStr;
        QString dateTemp;
        string dateStr;
        member *memPtr = NULL;
        executive *exPtr = NULL;
        Date date;


        while(!in.atEnd())
        {
            name = in.readLine();
            idNumStr = in.readLine();
            type = in.readLine();
            dateTemp = in.readLine();

            idNum = idNumStr.toDouble();
            nameStr = name.toStdString();
            typeStr = type.toStdString();
            dateStr = dateTemp.toStdString();


         date = Store::ConvertDate(dateStr);
            if(type == "Executive")
            {
                exPtr = new executive;
                exPtr->setAll(nameStr, typeStr, idNum, date, .035);
                memPtr = exPtr;
            }
            else
            {
                memPtr = new member;
                memPtr->setAll(nameStr, typeStr, idNum, date);
            }

            Store::addMember(memPtr);
        }
         Store::sortingMems(NAME);
         file.close();
}
/*!
 * \brief Store::saveMembers
 */
void Store::saveMembers()
{
    QString fName = QString::fromStdString(this->filename);
    QFile file(fName);

    if(!file.open(QIODevice::WriteOnly| QIODevice::Text))
        QMessageBox::information(0,"Member Read Error",file.errorString());
    QTextStream out(&file);
    for(unsigned int i = 0; i < members.size(); i++)
    {
        out.operator <<(QString::fromStdString(members.at(i)->saveMember()));
    }
    file.close();

}
/*!
 * \brief Store::saveItems
 */
void Store::saveItems()
{
    QString fName = QString::fromStdString(this->filenameIS);
    QFile file(fName);
    if(!file.open(QIODevice::WriteOnly| QIODevice::Text))
            QMessageBox::information(0,"Item Write Error",file.errorString());
        QTextStream out(&file);
        for(unsigned int i = 0; i < items.size(); i++)
        {
            out.operator <<(QString::fromStdString(items.at(i)->saveItem()));
        }
        file.close();
}
/*!
 * \brief Store::readItems
 */
void Store::readItems()
{
    QString fNameI = QString::fromStdString(this->filenameI);
    QFile file(fNameI);
    if(!file.open(QIODevice::ReadOnly))
                QMessageBox::information(0,"Purchases Read Error",file.errorString());

    QString quanTemp;
    QString prTemp;
    QString idTemp;
    QString dateTemp;
    QString nameTemp;


    string name;
    float price;
    string temp;
    string prStr;
    string idStr;
    string quanStr;
    int quantity;
    double idNum;
    string dateStr;
    Item *iPtr = NULL;
    Date date;
    unsigned int index= 0;



     QTextStream in(&file);

   while(!in.atEnd())
     {
         //read ins
        dateTemp = in.readLine();

        in >> idNum;
        in.skipWhiteSpace();
        nameTemp = in.readLine();
        in >> price;
        in.skipWhiteSpace();
        in >> quantity;
               in.skipWhiteSpace();

        dateStr = dateTemp.toStdString();
        date = Store::ConvertDate(dateStr);
        name = nameTemp.toStdString();
//


    iPtr = new Item;

       iPtr->SetAll(name, price, quantity, date, idNum);

        index = Store::searchMem(idNum);
        if(index < members.size())
        {
            members.at(index)->addTT(iPtr->getTotCost());
            members.at(index)->addTTW(iPtr->getTotwTax());
        }

        Store::addItem(iPtr);

     }
    file.close();
}

//MEMBER FUNCTIONS
/*!
 * \brief Store::addMember
 * \param newMem
 */
void Store::addMember(member *newMem)
{
	members.push_back(newMem);
}
/*!
 * \brief Store::removeMember
 * \param index
 */
void Store::removeMember(int index ){
	deque<member*>::iterator iter = members.begin() + index;
    members.erase(iter);
}
/*!
 * \brief Store::getMemCount
 * \return
 */
int Store::getMemCount() const
{
	return members.size();
}
/*!
 * \brief Store::PrintMember
 * \param index
 * \return
 */
string Store::PrintMember(int index) const
{
	stringstream output;

		output << members.at(index)->printMember();
		return output.str();

	//output << member.at
}
/*!
 * \brief Store::sortingMems
 * \param property
 */
void Store::sortingMems(int property)
{
	sort(members.begin(), members.end(), memberSort(property));
}
/*!
 * \brief Store::getMemName
 * \param index
 * \return
 */
string Store::getMemName(int index){
    member tempMem = *(members.at(index));
    return tempMem.getName();
}
/*!
 * \brief Store::getMemType
 * \param index
 * \return
 */
string  Store::getMemType(int index){
	return members.at(index)->getType();
}
/*!
 * \brief Store::getMemID
 * \param index
 * \return
 */
double  Store::getMemID(int index){
	return members.at(index)->getId();
}
/*!
 * \brief Store::getMemExp
 * \param index
 * \return
 */
Date  Store::getMemExp(int index){
	return members.at(index)->getExprDate();
}
/*!
 * \brief Store::searchMem
 * \param id
 * \return
 */
int Store::searchMem(double id)
{
	unsigned int index = 0;
	bool found = false;

  while(!found && index < members.size())
    {
        if(id == members.at(index)->getId())
        {
            found = true;
        }
        else
        {
            index ++;
        }



    }

return index;
}
/*!
 * \brief Store::getMemberIndex
 * \param name
 * \return
 */
int Store::getMemberIndex(string name) const
// ... pass in a member name to return  proper index for given name
{
    unsigned int index = 0;

    bool found = false;
    while(found == false && index < members.size())
    {

        if(name == members.at(index)->getName())
        {
            found = true;
        }
        else
        {
            index++;
        }

    }
    return index;
}
/*!
 * \brief Store::getRebate
 * \param index
 * \return
 */
string Store::getRebate(int index){
    if(members.at(index)->getType() == "Executive"){
        return members.at(index)->printRebate();
     }
}


//ITEM FUNCTIONS
/*!
 * \brief Store::getiName
 * \param index
 * \return
 */
string Store::getiName(int index) const{
	return items.at(index)->GetName();
}

/*!
/*! * \brief Store::getiID
/*! * \param index
/*! * \return
/*! */
double Store::getiID(int index) const{
	return items.at(index)->GetId();
}
/*!
 * \brief Store::getiQuan
 * \param index
 * \return
 */
int Store::getiQuan(int index) const{
	return items.at(index)->GetQty();
}
/*!
 * \brief Store::getiDate
 * \param index
 * \return
 */
Date Store::getiDate(int index) const{
	return items.at(index)->GetDate();
}
/*!
 * \brief Store::getiPrice
 * \param index
 * \return
 */
float Store::getiPrice(int index) const{
	return items.at(index)->GetPrice();
}
/*!
 * \brief Store::getTotCost
 * \param index
 * \return
 */
float Store::getTotCost(int index) const{
	return items.at(index)->getTotCost();
}
/*!
 * \brief Store::getTotwTax
 * \param index
 * \return
 */
float Store::getTotwTax(int index) const{
	return items.at(index)->getTotwTax();
}
/*!
 * \brief Store::sortingItems
 * \param property
 */
void Store::sortingItems(int property)
{
	sort(items.begin(), items.end(), ItemSort(property));
}
/*!
 * \brief Store::getItemCount
 * \return
 */
int Store::getItemCount() const
{
	return items.size();
}
/*!
 * \brief Store::addItem
 * \param newItem
 */
void Store::addItem(Item *newItem){
	items.push_back(newItem);
}
/*!
 * \brief Store::PrintItem
 * \param index
 * \return
 */
string Store::PrintItem(int index) const
{
	stringstream output;
	output << items.at(index)->printItem();
	return output.str();
}
/*!
 * \brief Store::setFilename
 * \param fname
 */
void Store::setFilename(string fname) {
    this->filename = fname;
}
/*!
 * \brief Store::setFilenameI
 * \param fname
 */
void Store::setFilenameI(string fname)
{
    this->filenameI = fname;
}
/*!
 * \brief Store::setFilenameIS
 * \param fname
 */
void Store::setFilenameIS(string fname)
{
    this->filenameIS = fname;
}
/*!
 * \brief Store::delItem
 * \param name
 */
void Store::delItem(string name){
    deque<Item*>::iterator iter;
    float refund;
    float rev;
    double id;
    for(unsigned int i = 0; i < items.size(); i++)
    {
        if(items.at(i)->GetName() == name){
            rev = items.at(i)->getTotwTax();
            refund = items.at(i)->getTotCost();
            id = items.at(i)->GetId();
            for( unsigned int z = 0; z < members.size(); z++){
                if(members.at(z)->getId() == id){
                    float temp;
                    temp = members.at(z)->getTotal() - refund;
                    members.at(z)->setTotal(temp);
                    temp = members.at(z)->getTotalwTax() - rev;
                    members.at(z)->setTotalwTax(temp);
                }
            }
            iter = items.begin() + i;
            items.erase(iter);
        }
    }
}
