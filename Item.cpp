/*
 * Item.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Nick
 */

#include "Item.h"
/*!
 * \brief Item::Item
 */
Item::Item() {
	name.clear();
	this->id = 0;
	this->quantity = 0;
	this->price = 0;
	this->totCost = 0;
	this->totwTax = 0;

}
/*!
 * \brief Item::~Item
 */
Item::~Item() {
	// TODO Auto-generated destructor stub
}
/*!
 * \brief Item::SetAll
 * \param name
 * \param price
 * \param quantity
 * \param date
 * \param id
 */
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
/*!
* \brief Item::SetId
 * \param id
 */
void Item::SetId(double id)
{
	this->id = id;
}
/*!
 * \brief Item::SetPrice
 * \param price
 */
void Item::SetPrice(float price)
{
	this->price = price;
}
/*!
 * \brief Item::SetName
 * \param name
 */
void Item::SetName(string name)
{
	this->name = name;
}
/*!
 * \brief Item::SetDate
 * \param date
 */
void Item::SetDate(Date date)
{
	this->purchDate = date;
}
/*!
 * \brief Item::GetId
 * \return
 */
double Item::GetId() const
{
	return this->id;
}
/*!
 * \brief Item::GetPrice
 * \return
 */
float Item::GetPrice() const
{
	return this->price;
}
/*!
 * \brief Item::GetName
 * \return
 */
string Item::GetName() const
{
	return this->name;
}
/*!
 * \brief Item::GetDate
 * \return
 */
Date Item::GetDate() const
{
	return this ->purchDate;
}
/*!
 * \brief Item::GetQty
 * \return
 */
int Item::GetQty() const
{
	return this->quantity;
}
/*!
 * \brief Item::CalcTotCost
 */
void Item::CalcTotCost()
{
this->totCost = this->price * this->quantity;
}
/*!
 * \brief Item::CalcTotwTax
 */
void Item::CalcTotwTax()
{
	this->totwTax = this->totCost +(this->totCost * .0825);
}
/*!
 * \brief Item::getTotwTax
 * \return
 */
float Item::getTotwTax()const{
	return this->totwTax;
}
/*!
 * \brief Item::getTotCost
 * \return
 */
float Item::getTotCost()const{
	return this->totCost;
}
/*!
 * \brief Item::printItem
 * \return
 */
string Item::printItem() const
{
	stringstream output;
	output << this->name << endl;
	output << fixed << setprecision(2) <<this->price << endl;
	output << fixed << setprecision(0) <<this->id << endl;
	output << this->quantity << endl;
	output << fixed << setprecision(2) << this->totCost << endl;
	output << fixed << setprecision(2) << this->totwTax << endl;
	output << this->purchDate.DisplayDate() << endl;
	return output.str();
}
/*!
 * \brief Item::saveItem
 * \return
 */
string Item::saveItem() const
{
    stringstream output;
    output << this->purchDate.DisplayDate() << endl;
    output << this->id << endl;
    output << this->name << endl;
    output << left << setw(8) << this->price << this->quantity << endl;

    return output.str();
}
