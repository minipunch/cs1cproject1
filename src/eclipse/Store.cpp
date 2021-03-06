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
	unsigned int index= 0;

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
		
		index = Store::searchMem(idNum);
		if(index < members.size())
		{
			members.at(index)->addTT(iPtr->getTotCost());
			members.at(index)->addTTW(iPtr->getTotwTax());
		}

		Store::addItem(iPtr);

	}
	//Store::sortingItems(NAME);
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
