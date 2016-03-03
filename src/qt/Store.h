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
#include <QFileDialog>
#include "Item.h"

class Store {

private:
    // TODO: add list of items purchased at the store
	deque<member*> members;
    deque<Item*> mem;
    string filename;
public:
    // constructors
	Store();
	~Store();
    // setters
    void setFilename(string fname);
    // getters
    // miscellaneous
	void addMember(member *newMem);
	void removeMember(int index);
	void sorting(int property);
	void readIn();
	Date ConvertDate(string dateIn);
	int search(string name);
	int search(int num);
	int search(Date dateSearch);
	int getMemCount() const;
    member* getMember(int x) const;
    string getMemberName(int x) const;
    string  PrintMember(int index) const;
};

#endif /* STORE_H_ */
