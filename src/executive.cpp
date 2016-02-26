#include "executive.h"

executive::executive(): rebateAmount(0)
{
}

executive::executive(double newNum) : rebateAmount(newNum)
{
}

void executive::setRebateAmount(double num)
{
	this->rebateAmount = num;
}

double executive::getRebateAmount() const
{
	return this->rebateAmount;
}

double executive::calculateRebate() const
{
	return (this->getTotal() * 3.5);
}

void executive::printExecutive() const {
	printMember();
	cout << "Rebate Amount: " << this->rebateAmount;
}
