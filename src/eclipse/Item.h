/*
 * Item.h
 *
 *  Created on: Feb 26, 2016
 *      Author: Nick
 */

#ifndef ITEM_H_
#define ITEM_H_
#include <string>
#include <iostream>
#include<sstream>
using namespace std;
#include "date.h"
#include "itemnames.h"
class Item {
private:
	string name;
	float price;
	double id;
	int quantity;
	Date purchDate;
	float totCost;

protected:
	void CalcTotCost();
public:
	Item();
	~Item();

	void SetAll(string name, float price, int quantity, Date date, double id);
	void SetId(double id);
	void SetPrice(float price);
	void SetName(string name);
	void SetDate(Date date);

	double GetId() const;
	float GetPrice() const;
	string GetName() const;
	Date GetDate()   const;
	int GetQty() const;
	string printItem() const;
};

struct ItemSort
{
	int property;
		ItemSort(int property) {this->property = property;}
		 bool operator()(const Item *i1, const Item *i2) const {
			if(property == NAME)
			{
				return i1->GetName() < i2->GetName();
			}
			else
			{
				return i1->GetId() < i2->GetId();
			}
			//data operator overloading
		}
};



#endif /* ITEM_H_ */
