/*
 * executive.h
 *
 *  Created on: Feb 23, 2016
 *      Author: josh
 */

#ifndef EXECUTIVE_H_
#define EXECUTIVE_H_
#include "member.h"

class executive : public member {
private:
	double rebateAmount;
public:
	// constructors
	executive();
	virtual ~executive();
	executive(double newRebate);
	// setters
	void setRebateAmount(double num);
	// getters
	double getRebateAmount() const;
	// miscellaneous
	double calculateRebate() const;
	void printExecutive() const;
};

#endif /* EXECUTIVE_H_ */
