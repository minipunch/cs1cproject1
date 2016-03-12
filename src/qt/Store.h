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
    string filename;
    string filenameI;

    string filenameIS;
public:
	Store();
	~Store();
	Date ConvertDate(string dateIn);
	int searchMem(string name);
	int searchMem(double id);
	int searchMem(Date dateSearch);

    //misc
    void setFilename(string fname);
    void setFilenameI(string fname);
	//Item Functions
	void addItem(Item *newItem);
	int getItemCount() const;
    string PrintItem(int index) const;
    void readItems();
    float getTotwTax(int index) const;
	float getTotCost(int index) const;
	void sortingItems(int property);
	string getiName(int index) const;
	double getiID(int index) const;
	int getiQuan(int index) const;
	Date getiDate(int index) const;
	float getiPrice(int index) const;

	//Member Functions
	void addMember(member *newMem);
    string getMemName(int index);
    string getMemType(int index);
    double getMemID(int index);
    Date getMemExp(int index);
    string  PrintMember(int index) const;
	int getMemCount() const;
	void readInMembers();
    void saveMembers();
	void removeMember(int index);
	void sortingMems(int property);
};

#endif /* STORE_H_ */
