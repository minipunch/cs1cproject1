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
/*!
 * \brief Keeps track of all members and items
 *
 * This class keeps track of all of the members and items and has the methods to interact with them.
 *
 * Within this Class:
 * - Deque of members
 * - Deque of Items
 * - filenames for saving and reading in items/members
 */
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
    /*!
     * \brief Constructor
     */
	Store();
    /*!
         * \brief destructor
         */
	~Store();
    /*!
     * \brief Converts a string to Date object
     *
     * Converts a string to a date object
     * Used for reading in members and items
     * \param dateIn string to be converted
     * \return date created
     */
	Date ConvertDate(string dateIn);
    //misc
    /*!
     * \brief sets the members file name
     * \param fname filename for member file
     */
    void setFilename(string fname);
    /*!
     * \brief sets items file name
     * \param fname filename for item file
     */
    void setFilenameI(string fname);
    /*!
     * \brief sets item saving file name
     * \param fname filename for saving items file
     */
    void setFilenameIS(string fname);

	//Item Functions
    /*!
     * \brief adds an item pointer to the list
     *
     *
     * \param newItem item pointer to be added
     */
	void addItem(Item *newItem);

    /*!
     * \brief returns the number of items in the item list
     *
     * returns size of item deque
     * \return number of items
     */
	int getItemCount() const;
    /*!
     * \brief Print single Item
     * \param index location in list
     * \return stringstream of output
     */
    string PrintItem(int index) const;
    /*!
     * \brief reads in item file
     *
     * reads in an item file that the user specifies and adds them to the list as item pointers
     */
    void readItems();
    /*!
     * \brief saves item list to file
     *
     * saves the item list to a file the user can pick
     */
    void saveItems();
    /*!
     * \brief gets total spent w/ tax for a single item
     * \param index location in list
     * \return total cost
     */
    float getTotwTax(int index) const;
    /*!
     * \brief gets total cost w/ tax for a single item
     * \param index location in list
     * \return total cost with tax
     */
	float getTotCost(int index) const;
    /*!
     * \brief sorts Item list
     * \param property how list is sorted
     */
	void sortingItems(int property);
    /*!
     * \brief gets name of single item
     * \param index location in list
     * \return name of the item
     */
	string getiName(int index) const;
    /*!
     * \brief gets buyer id of single item
     * \param index location in list
     * \return id of the item buyer
     */
	double getiID(int index) const;
    /*!
     * \brief gets quantity of a single item
     * \param index location in list
     * \return quantity of the item
     */
	int getiQuan(int index) const;
    /*!
     * \brief gets the purchase date of a single item
     * \param index location in list
     * \return purchase date of the item
     */
	Date getiDate(int index) const;
    /*!
     * \brief gets the price of a single item
     * \param index location in list
     * \return price of single item
     */
	float getiPrice(int index) const;
    /*!
     * \brief removes an item from everyones purchase list
     *
     * \param name name of item to delete
     */
    void delItem(string name);
    /*!
      * \brief deletes a single item
      * \param index location in list
      */
     void removeItem(int index);

	//Member Functions

     /*!
      * \brief searches members based on id
      * \param id  id to search
      * \return index of the found name
      */
     int searchMem(double id);
     /*!
      * \brief searches members based on name
      * \param name name to search
      * \return index of the found name
      */
    int getMemberIndex(string name) const;
    /*!
     * \brief add new member to the list
     * \param newMem member pointer to be added
     */
	void addMember(member *newMem);
    /*!
     * \brief gets name of single member
     * \param index location in list
     * \return member's name
     */
    string getMemName(int index);
    /*!
     * \brief gets the membership type of a single member
     * \param index location in list
     * \return membership type
     */
    string getMemType(int index);

    /*!
     * \brief get id number of a single member
     * \param index location in list
     * \return Member's id
     */
    double getMemID(int index);
    /*!
     * \brief gets expiration date of a single member
     * \param index location in list
     * \return expiration date
     */
    Date getMemExp(int index);
    /*!
     * \brief Print single member
     * \param index location in list
     * \return stringstream of the output
     */
    string  PrintMember(int index) const;
    /*!
     * \brief returns the number of members in the list
     * \return number of members
     */
	int getMemCount() const;
    /*!
     * \brief reads in member list
     *
     * Reads in a valid file of members to be added to the list as member pointers
     */
	void readInMembers();
    /*!
     * \brief saves the member list to a file
     */
    void saveMembers();
    /*!
     * \brief gets total spent for a single member
     * \param index location in list
     * \return member's total cost
     */
    double getMTotCost (int index);

    /*!
     * \brief removes a Member
     *
     * Removes a member from the list and deletes their purchases from the item list
     * \param index location in list
     */
	void removeMember(int index);
    /*!
     * \brief sorts member list
     * \param property how the list is sorted
     */
    void sortingMems(int property);
    /*!
     * \brief gets the rebate of a single member
     * \param index location in the list
     * \return the rebate as a string to output
     */
    string getRebate(int index);

    /*!
         * \file Store.h
         * \brief  Header for Store class
         *
         * This file contains all of the declarations of the Store class
         */
};

#endif /* STORE_H_ */
