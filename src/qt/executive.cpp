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

void executive::calculateRebate()
{

    rebateAmount = member::getTotal() + (member::getTotal() * .035);
}

void executive::printExecutive() const {
	member::printMember();
	cout << "Rebate Amount: " << this->rebateAmount;
}

string executive::printRebate()
{

    stringstream output;
    executive::calculateRebate();
    output << this->rebateAmount << endl;
    return output.str();

}
void executive::renew()
{
   member::addTT(125.00);
   member::addTTW(125.00);
}
