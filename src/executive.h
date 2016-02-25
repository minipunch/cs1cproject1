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
	double rebateAmount;
public:
	// constructors
	executive();
	executive(double num);
	// setters
	void setRebateAmount(double num);
	// getters
	double getRebateAmount() const;
	double calculateRebate();
};

#endif /* EXECUTIVE_H_ */
