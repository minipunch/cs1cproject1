#include "executive.h"

executive::executive(): rebateAmount(0)
{
}

executive::~executive(){}

executive::executive(float newNum) : rebateAmount(newNum)
{
}

void executive::setAll(string name, string type, double id, Date exprDate, float rebate)
{
	member::setAll(name, type, id, exprDate);
	this->rebateAmount = rebate;
}
void executive::setRebateAmount(float newRebate)
{
	this->rebateAmount = newRebate;
}

float executive::getRebateAmount() const
{
	return this->rebateAmount;
}

float executive::calculateRebate() const
{
	//this will change
	return (this->getTotal() * 3.5);
}

void executive::printExecutive(){
	member::printMember();
	cout << "Rebate Amount: " << this->rebateAmount;
}
