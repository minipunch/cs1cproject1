/*
 * member.h
 *
 *  Created on: Feb 23, 2016
 *      Author: josh
 */

#ifndef MEMBER_H_
#define MEMBER_H_

#include <string>
#include "date.h"
using namespace std;

class member {
	string name;
	string type;
	double id;
	double total;
	Date exprDate;
public:
	// constructors
	member();
	member(string name, double id);
	member(string name, string type, double id, double total, Date exprDate);
	// setters
	void setName(string name);
	void setType(string type);
	void setId(double id);
	void setTotal(double total);
	void setExprDate(int month, int day, int year);
	// getters
	string getName() const;
	string getType() const;
	double  getId() const;
	double  getTotal() const;
	Date getExprDate() const;
	//miscellaneous
	void printMember() const;

};




#endif /* MEMBER_H_ */
