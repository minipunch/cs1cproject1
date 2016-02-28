/*
 * Store.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Nick
 */

#include "Store.h"

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
	ifstream inFile;
	inFile.open("members.txt");
	string name;
	string type;
	double idNum;
	string dateTemp;
	member *memPtr;
	executive *exPtr;
	Date date;

	//read from the input file
	while(inFile)
	{
		getline(inFile, name);
		inFile >> idNum;
		inFile.ignore(1000, '\n');
		getline(inFile, type);
		getline(inFile, dateTemp);

		date = Store::ConvertDate(dateTemp);
		if(type == "Executive"){
			exPtr = new executive;
			exPtr->setAll(name, type, idNum, 0, date, .035);
			memPtr = exPtr;
		}
		else {
			memPtr = new member;
			memPtr->setAll(name, type, idNum, 0, date);
		}
		Store::addMember(memPtr);
	}


}


void Store::addMember(member *newMem)
{
	members.push_back(newMem);
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
