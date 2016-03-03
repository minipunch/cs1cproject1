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
#include "date.h"
using namespace std;
class Item {

private:
	string name;
	float price;
    double id;
    Date date;
    int quantity;
    // ... and more
public:  
   // constructors
	Item();
	~Item();
    // getters

    // setters
};

#endif /* ITEM_H_ */
