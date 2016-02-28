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
#include <fstream>

class Store {

private:
	//add list of items purchased @ store
	deque<member*> members;
public:
	Store();
	~Store();
	void addMember(member *newMem);
	void removeMember(int index);
	void sorting(int property);
	void readIn();
	Date ConvertDate(string dateIn);
	int search(string name);
	int search(int num);
	int search(Date dateSearch);
	int getMemCount() const;

    string  PrintMember(int index) const;
};

#endif /* STORE_H_ */
