/*
 * member.h
 *
 *  Created on: Feb 23, 2016
 *      Author: josh
 */

#ifndef MEMBER_H_
#define MEMBER_H_
#include "itemnames.h"
#include <string>
#include "date.h"
#include <deque>
#include<algorithm>
#include <sstream>
#include <QTextStream>
#include <QString>
using namespace std;
/*!
 * \brief Represents a regular member
 *
 * In this Class:
 * - member's name
 * - id number
 * - total spent (running total)
 * - total spent w/ tax (runnign total)
 * - membership expiration date
 */
class member {
	string name;
	string type;
	double id;
	double total;
	double totalwTax;
	Date exprDate;
public:
    /*!
     * \brief default constructor
     */
	member();
    /*!
     * \brief destructor
     */
	virtual ~member();
    /*!
     * \brief alternate constructor #1
     *
     * Initializes with name and id
     * \param name new name
     * \param id   new id
     */
	member(string name, double id);
    /*!
     * \brief alternate constructor #2
     *
     * sets all attributes
     * \param name  new name
     * \param type  type of member
     * \param id    new id
     * \param total new total spent
     * \param exprDate member expiration date
     */
	member(string name, string type, double id, double total, Date exprDate);
	// setters
    /*!
     * \brief sets all attributes
     *
     * sets all attributes except the totals
     * \param name     new name
     * \param type     type of member
     * \param id       new id
     * \param exprDate member expiration date
     */
	void setAll(string name, string type, double id , Date exprDate);
    /*!
     * \brief Set name of a member
     * \param name new name
     */
	void setName(string name);
    /*!
     * \brief set membership type
     * \param type new type
     */
	void setType(string type);
    /*!
     * \brief Set member id number
     * \param id new id
     */
	void setId(double id);
    /*!
     * \brief Sets member's total spent
     * \param total new total
     */
	void setTotal(double total);
    /*!
     * \brief sets Sets member's total spent with tax included
     * \param total new total
     */
    void setTotalwTax(double total);
    /*!
     * \brief Set's the expiration date
     * \param exprDate new member expiration date
     */
	void setExprDate(Date exprDate);
	// getters

    /*!
     * \brief Gets member's name
     * \return member name
     */
	string getName() const;
    /*!
     * \brief Gets member membership type
     * \return membership type
     */
	string getType() const;
    /*!
     * \brief Gets member's Id number
     * \return member's id number
     */
	double  getId() const;
    /*!
     * \brief Gets member's total spent
     * \return member's total spent
     */
	double  getTotal() const;
    /*!
     * \brief Get's member's total spent
     * \return member's total spent
     */
    double  getTotalwTax() const;\
    /*!
     * \brief Gets member's expiration date
     * \return member's expiration date
     */
	Date getExprDate() const;
	//miscellaneous
    /*!
     * \brief Prints a member
     *
     * Used to print a member
     * \return  stringstream of a printout
     */
    QString printMember() const;
    /*!
     * \brief Alternate print member
     *
     * Used for saving a member to a file
     * \return stringstream of output
     */
    string saveMember() const;
    /*!
     * \brief add to total cost
     * \param a amount being added
     */
	void addTT(float a);
    /*!
     * \brief add to total w/ tax
     * \param a amount being added
     */
	void addTTW(float a);
    /*!
     * \brief renew membership
     *
     * adds the renewal cost of this membership to the running totals
     */
    virtual void renew();
    /*!
     * \brief prints current rebate amount
     * \return stringstream of the output
     */
    virtual string printRebate();
};
/*!
 * \brief Functor for sorting members
 *
 * This functor helps sort a member list by various attributes
 *
 * Can Sort by:
 * - Member's Name
 * - Member Id number
 */
struct memberSort{
    int property; //!< determines how the members are sorted
    /*!
     * \brief set property
     * \param property how the sort is being done
     */
	memberSort(int property) {this->property = property;}
    /*!
      * \brief  overloaded ()operator
      * \param m1 first member
      * \param m2 second member
      * \return
      */
	 bool operator()(const member *m1, const member *m2) const {
		if(property == NAME)
		{
			return m1->getName() < m2->getName();
		}
		else
		{
			return m1->getId() < m2->getId();
		}
		//data operator overloading
	}

     /*!
      * \file member.h
      * \brief  Header for member class
      *
      * This file contains all of the attributes and methods for the member class
      */
};



#endif /* MEMBER_H_ */
