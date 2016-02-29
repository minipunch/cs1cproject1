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
using namespace std;
class Item {

private:
	string name;
	float price;
    // ... and more
public:  
	Item();
	~Item();
};

#endif /* ITEM_H_ */
