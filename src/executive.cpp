#include "executive.h"

executive::executive(): rebateAmount(0)
{
}

executive::~executive(){}

executive::executive(double newNum) : rebateAmount(newNum)
{
}

void executive::setRebateAmount(double newRebate)
{
	this->rebateAmount = newRebate;
}

double executive::getRebateAmount() const
{
	return this->rebateAmount;
}

double executive::calculateRebate() const
{
	//this will change
	return (this->getTotal() * 3.5);
}

void executive::printExecutive() const {
	printMember();
	cout << "Rebate Amount: " << this->rebateAmount;
}
