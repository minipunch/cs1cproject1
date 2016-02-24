#include "executive.h"

executive::executive()
{
	member();
	rebateAmount = 0;
}

executive::executive(double newNum)
{
	member();
	this->rebateAmount = newNum;
}

void executive::setRebateAmount(double num)
{
	this->rebateAmount = num;
}

double executive::getRebateAmount() const
{
	return this->rebateAmount;
}
