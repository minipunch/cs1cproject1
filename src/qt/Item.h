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
/*!
 * \brief Class to represent the items in the store
 *
 * This class represents an item
 *
 * Parts:
 * - Item name
 * - Individual Price
 * - quantity
 * - date of purchase
 * - total cost (quantity X price)
 * - total with tax (total w/ tax applied)
 */
class Item {
private:
	string name;
	float price;
	double id;
	int quantity;
	Date purchDate;
	float totCost; //w/o tax
	float totwTax; // w/ tax

protected:
    /*!
     * \brief Calculates the total cost of an item object
     *
     * Quantity X price = totalCost
     */
	void CalcTotCost();
    /*!
     * \brief Calculates the total cost with tax applied
     *
     * totwTax = totCost X tax rate.
     */
	void CalcTotwTax();
public:
    /*!
     * \brief default constructor
     */
	Item();
    /*!
      \brief destructor
      */
	~Item();
    /*!
     * \brief Sets all attributes of an item
     * \param name     item name
     * \param price    item individual price
     * \param quantity item quantity
     * \param date     item purchase date
     * \param id       item id of who bought the item
     */
	void SetAll(string name, float price, int quantity, Date date, double id);
    /*!
     * \brief set the id of an item
     *
     * \param id  new id
     */
	void SetId(double id);
    /*!
     * \brief Sets the single price of an item
     * \param price  new price
     */
	void SetPrice(float price);
    /*!
     * \brief Sets the name of an item
     * \param name  new name
     */
	void SetName(string name);

    /*!
     * \brief Sets the purchase date of an item
     * \param date
     */
	void SetDate(Date date);
    /*!
     * \brief Gets Id of buyer
     * \return buyer's id number
     */
	double GetId() const;

    /*!
     * \brief Gets Price of an item
     * \return price of an item
     */
	float GetPrice() const;

    /*!
     * \brief Gets the name of an item
     * \return  item's name
     */
	string GetName() const;
    /*!
     * \brief Gets the purchase Date
     * \return purchase date
     */
	Date GetDate()   const;
    /*!
     * \brief Gets quantity bought
     * \return quantity bought
     */
	int GetQty() const;
    /*!
     * \brief prints an item
     * \return stringstream of the item print
     */
	string printItem() const;
    /*!
     * \brief saves and item
     *
     * alternate print method for saving items to a file
     * \return stringstream of the item print
     */
    string saveItem() const;
    /*!
     * \brief gets total with tax
     * \return total with tax
     */
	float getTotwTax() const;
    /*!
     * \brief gets the total cost
     * \return total cost
     */
	float getTotCost() const;

    /*!
     * \file Item.h
     * \brief  Header for Item class
     *
     * This file contains all of the declarations of the Item class
     */

};
/*!
 * \brief functor for sorting item list.
 *
 * Functor for sorting the list of items by various attributes
 * Can sort by:
 * - Item name
 * - Individual Price
 * - Buyer Id
 */
struct ItemSort
{
    int property; //!< determines how the items are sorted
    /*!
         * \brief set property
         * \param property determines what to sort by
         */
		ItemSort(int property) {this->property = property;}
        /*!
          * \brief overloaded () operator to sort
          * \param i1 first item
          * \param i2 second item
          * \return which attribute was larger
          */
		 bool operator()(const Item *i1, const Item *i2) const {
			if(property == NAME)
			{
				return i1->GetName() < i2->GetName();
			}
			else if(property == ID)
			{
				return i1->GetId() < i2->GetId();
			}
			else
			{
				return i1->GetPrice() < i2->GetPrice();
			}

		}
};



#endif /* ITEM_H_ */
