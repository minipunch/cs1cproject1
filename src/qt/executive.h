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
	float rebateAmount;
public:
	// constructors
	executive();
	virtual ~executive();
	executive(float newRebate);
	// setters
	void setRebateAmount(float num);
	void setAll(string name, string type, double id, Date exprDate, float rebate);
	// getters
	float getRebateAmount() const;
	// miscellaneous
    void calculateRebate() ;
	void printExecutive() const;
    virtual string printRebate();
    virtual void renew();
};

#endif /* EXECUTIVE_H_ */
