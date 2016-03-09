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
Store::Store() {


	// TODO Auto-generated constructor stub

}

Store::~Store() {
	//cout << "test" << endl;
	// TODO Auto-generated destructor stub
}

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
}
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
//        idTemp = in.readLine();
        in >> idNum;
        in.skipWhiteSpace();
        nameTemp = in.readLine();
        in >> price;
        in.skipWhiteSpace();
        in >> quantity;
               in.skipWhiteSpace();
//        quanTemp = in.readLine();
        dateStr = dateTemp.toStdString();
        date = Store::ConvertDate(dateStr);
        name = nameTemp.toStdString();
//        temp = quanTemp.toStdString();
//        idStr = idTemp.toStdString();
//        prStr = temp.substr(0,5);
//        quanStr = temp.substr(5,6);
//        idNum = ::atof(idStr.c_str());
//        price = ::atof(prStr.c_str());
//        quantity = ::atoi(quanStr.c_str());


    iPtr = new Item;

       iPtr->SetAll(name, price, quantity, date, idNum);
        //iPtr->SetAll("Milk",13.37, 69, date, 12345 );
        //index = Store::searchMem(idNum);
//        if(index < members.size())
//        {
//            //members.at(index)->addTT(iPtr->getTotCost());
//            //members.at(index)->addTTW(iPtr->getTotwTax());
//        }

        Store::addItem(iPtr);


     }



}

//MEMBER FUNCTIONS
void Store::addMember(member *newMem)
{
	members.push_back(newMem);
}

void Store::removeMember(int index ){
	deque<member*>::iterator iter = members.begin() + index;
	members.erase(iter);
}
int Store::getMemCount() const
{
	return members.size();
}
string Store::PrintMember(int index) const
{
	stringstream output;

		output << members.at(index)->printMember();
		return output.str();

	//output << member.at
}
void Store::sortingMems(int property)
{
	sort(members.begin(), members.end(), memberSort(property));
}
string Store::getMemName(int index){
	return members.at(index)->getName();
}
string  Store::getMemType(int index){
	return members.at(index)->getType();
}
double  Store::getMemID(int index){
	return members.at(index)->getId();
}
Date  Store::getMemExp(int index){
	return members.at(index)->getExprDate();
}

int Store::searchMem(double id)
{
	unsigned int index = 0;
	bool found = false;
//cout << "here";
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

	//cout << "Enters loop" << endl;

}

return index;
}



//ITEM FUNCTIONS
string Store::getiName(int index) const{
	return items.at(index)->GetName();
}
double Store::getiID(int index) const{
	return items.at(index)->GetId();
}
int Store::getiQuan(int index) const{
	return items.at(index)->GetQty();
}
Date Store::getiDate(int index) const{
	return items.at(index)->GetDate();
}
float Store::getiPrice(int index) const{
	return items.at(index)->GetPrice();
}
float Store::getTotCost(int index) const{
	return items.at(index)->getTotCost();
}
float Store::getTotwTax(int index) const{
	return items.at(index)->getTotwTax();
}
void Store::sortingItems(int property)
{
	sort(items.begin(), items.end(), ItemSort(property));
}
int Store::getItemCount() const
{
	return items.size();
}
void Store::addItem(Item *newItem){
	items.push_back(newItem);
}
string Store::PrintItem(int index) const
{
	stringstream output;
	output << items.at(index)->printItem();
	return output.str();
}
void Store::setFilename(string fname) {
    this->filename = fname;
}
void Store::setFilenameI(string fname)
{
    this->filenameI = fname;
}
