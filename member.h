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
using namespace std;
/*!
 * \brief The member class
 */
class member {
	string name;
	string type;
	double id;
	double total;
	double totalwTax;
	Date exprDate;
public:
	// constructors
	member();
	virtual ~member();
	member(string name, double id);
	member(string name, string type, double id, double total, Date exprDate);
	// setters
	void setAll(string name, string type, double id , Date exprDate);
	void setName(string name);
	void setType(string type);
	void setId(double id);
	void setTotal(double total);
    void setTotalwTax(double total);
	void setExprDate(Date exprDate);
	// getters
	string getName() const;
	string getType() const;
	double  getId() const;
	double  getTotal() const;
    double  getTotalwTax() const;
	Date getExprDate() const;
	//miscellaneous
	string printMember() const;
    string saveMember() const;
	void addTT(float a);
	void addTTW(float a);
    virtual void renew();
    virtual string printRebate();
};
/*!
 * \brief The memberSort struct
 */

struct memberSort{
	int property;
	memberSort(int property) {this->property = property;}
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
};



#endif /* MEMBER_H_ */
