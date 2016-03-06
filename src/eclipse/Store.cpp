/*
 * Store.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Nick
 */

#include "Store.h"

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
	//for eclipse only!!!!!!
	//must be rebuilt for qt
	while(!inFile.eof())
	{
		getline(inFile, name);
		inFile >> idNum;
		inFile.ignore(1000, '\n');
		getline(inFile, type);
		getline(inFile, dateTemp);
		date = Store::ConvertDate(dateTemp);
		if(type == "Executive"){
			exPtr = new executive;
			exPtr->setAll(name, type, idNum, date, .035);
			memPtr = exPtr;
		}
		else {
			memPtr = new member;
			memPtr->setAll(name, type, idNum, date);
		}
		Store::addMember(memPtr);

		memPtr = NULL;
		exPtr = NULL;
	}
	Store::sortingMems(NAME);
}
void Store::readItems()
{
	ifstream inFile;
	inFile.open("day1.txt");
	string name;
	float price;
	int quantity;
	double idNum;
	string dateTemp;
	Item *iPtr;
	Date date;

	//INCOMPLETE AND EXAMPLE
	while (!inFile.eof()) {
		getline(inFile, dateTemp);
		//cout << dateTemp << endl;
		date = ConvertDate(dateTemp);
		inFile >> idNum;
		//cout << idNum << endl;
		inFile.ignore(1000, '\n');
		getline(inFile, name);
	//	cout << name << endl;
		inFile >> price;
		//cout << price << endl;
		inFile >> quantity;
		//cout << quantity << endl;
		inFile.ignore(1000, '\n');
		iPtr = new Item;
	//	cin.ignore(1000, '\n');
		iPtr->SetAll(name, price, quantity, date, idNum);

		Store::addItem(iPtr);
		//iPtr = NULL;
	}
	Store::sortingItems(NAME);
}


void Store::addMember(member *newMem)
{
	members.push_back(newMem);
}

void Store::addItem(Item *newItem){
	items.push_back(newItem);
}

int Store::getMemCount() const
{
	return members.size();
}

int Store::getItemCount() const
{
	return items.size();
}

string Store::PrintMember(int index) const
{
	stringstream output;

		output << members.at(index)->printMember();
		return output.str();

	//output << member.at
}

string Store::PrintItem(int index) const
{
	stringstream output;
	output << items.at(index)->printItem();
	return output.str();
}

void Store::sortingMems(int property)
{
	sort(members.begin(), members.end(), memberSort(property));
}
void Store::sortingItems(int property)
{
	sort(items.begin(), items.end(), ItemSort(property));
}
