/*
 * Store.h
 *
 *  Created on: Feb 26, 2016
 *      Author: Nick
 */

#ifndef STORE_H_
#define STORE_H_
#include "executive.h"
#include "itemnames.h"
#include "Item.h"
#include <fstream>

class Store {

private:
	//list of all members registered at a store
	deque<member*> members;
	//list of all items bought at this store
	deque<Item*> items;
public:
	Store();
	~Store();
	void addMember(member *newMem);
	void addItem(Item *newItem);
	void removeMember(int index);
	void sorting(int property);
	void readInMembers();
	void readInPurch();
	Date ConvertDate(string dateIn);
	int search(string name);
	int search(int num);
	int search(Date dateSearch);
	int getMemCount() const;
	int getItemCount() const;
    string  PrintMember(int index) const;
    string PrintItem(int index) const;
    void readItems();
    void addItem(Item *i)
};

#endif /* STORE_H_ */
