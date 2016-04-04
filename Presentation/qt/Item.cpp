/*
 * Item.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Nick
 */

#include "Item.h"
/*!
 * \file Item.cpp
 * \brief Source file forItem class methods
 *
 * This file contains all of the definitions for the Item class
 */
Item::Item() {
	name.clear();
	this->id = 0;
	this->quantity = 0;
	this->price = 0;
	this->totCost = 0;
	this->totwTax = 0;

}

Item::~Item() {
	// TODO Auto-generated destructor stub
}

void Item::SetAll(string name, float price, int quantity, Date date, double id)
{
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	this->purchDate = date;
	this->id = id;
	Item::CalcTotCost();
	Item::CalcTotwTax();
}

void Item::SetId(double id)
{
	this->id = id;
}

void Item::SetPrice(float price)
{
	this->price = price;
}

void Item::SetName(string name)
{
	this->name = name;
}
void Item::SetDate(Date date)
{
	this->purchDate = date;
}
double Item::GetId() const
{
	return this->id;
}
float Item::GetPrice() const
{
	return this->price;
}
string Item::GetName() const
{
	return this->name;
}

Date Item::GetDate() const
{
	return this ->purchDate;
}

int Item::GetQty() const
{
	return this->quantity;
}

void Item::CalcTotCost()
{
this->totCost = this->price * this->quantity;
}

void Item::CalcTotwTax()
{
	this->totwTax = this->totCost +(this->totCost * .0825);
}

float Item::getTotwTax()const{
	return this->totwTax;
}
float Item::getTotCost()const{
	return this->totCost;
}

string Item::printItem() const
{
    stringstream output;
    string name2;
    name2 = this->name;
    if(name2.size() > 25){
        string a = "...";
        name2 = name2.substr(0,25);
        name2.append(a);
    }
    output << left;
    output << setw(30) << name2 << "\t\t";
    output << fixed << setprecision(2)<< setw(10) << this->price << "\t";
    output << fixed << setprecision(0) << setw(10) <<this->id;
    if(this->quantity > 999){
        output << setw(16) << this->quantity;
    }
    else if (this->quantity > 9){
        output << setw(18) << this->quantity;
    }
    else{
        output << setw(19) << this->quantity;
    }
    if(this->totCost > 10000){
        output << fixed << setprecision(2) << setw(10) << this->totCost;
        output << fixed << setprecision(2) << setw(7) << this->totwTax << "\t";
    }
    else{
        output << fixed << setprecision(2) << setw(12) << this->totCost << "\t";
        output << fixed << setprecision(2) << setw(9) << this->totwTax << "\t";
    }
    output << setw(10) << this->purchDate.DisplayDate() << endl;
	return output.str();
}

string Item::saveItem() const
{
    stringstream output;
    output << this->purchDate.DisplayDate() << endl;
    output << this->id << endl;
    output << this->name << endl;
    output << left << setw(8) << this->price << this->quantity << endl;

    return output.str();
}
