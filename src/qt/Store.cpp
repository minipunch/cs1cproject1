/*
 * Store.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Nick
 */

#include "Store.h"
#include "member.cpp"
#include "executive.cpp"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Store::Store() {

	ifstream inFile;
	// TODO Auto-generated constructor stub

}

Store::~Store() {
	cout << "test" << endl;
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

void Store::readIn()
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
            exPtr->setAll(nameStr, typeStr, idNum, 0, date, .035);
            memPtr = exPtr;
        }
        else
        {
            memPtr = new member;
            memPtr->setAll(nameStr, typeStr, idNum, 0, date);
        }

        Store::addMember(memPtr);
    }
     Store::sorting(NAME);
}

void Store::addMember(member *newMem)
{
    this->members.push_back(newMem);
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
}

void Store::sorting(int property)
{
	sort(members.begin(), members.end(), memberSort(property));
}

member* Store::getMember(int index) const {
    return this->members.at(index);
}

string Store::getMemberName(int x) const {
    string temp;
    member* tempMem;

    tempMem = this->members.at(x);

    temp = tempMem->getName();

    return temp;
}

void Store::setFilename(string fname) {
    this->filename = fname;
}
