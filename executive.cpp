#include "executive.h"
/*!
 * \brief executive::executive
 */
executive::executive(): rebateAmount(0)
{
}
/*!
 * \brief executive::~executive
 */
executive::~executive(){}

executive::executive(float newNum) : rebateAmount(newNum)
{
}
/*!
 * \brief executive::setAll
 * \param name
 * \param type
 * \param id
 * \param exprDate
 * \param rebate
 */
void executive::setAll(string name, string type, double id, Date exprDate, float rebate)
{
	member::setAll(name, type, id, exprDate);
	this->rebateAmount = rebate;
}
/*!
 * \brief executive::setRebateAmount
 * \param newRebate
 */
void executive::setRebateAmount(float newRebate)
{
	this->rebateAmount = newRebate;
}
/*!
 * \brief executive::getRebateAmount
 * \return
 */
float executive::getRebateAmount() const
{
	return this->rebateAmount;
}
/*!
 * \brief executive::calculateRebate
 */
void executive::calculateRebate()
{

    rebateAmount = (member::getTotal() * .035);
}
/*!
 * \brief executive::printExecutive
 */
void executive::printExecutive() const {
	member::printMember();
	cout << "Rebate Amount: " << this->rebateAmount;
}
/*!
 * \brief executive::printRebate
 * \return
 */
string executive::printRebate()
{
    stringstream output;
    executive::calculateRebate();
    output << setprecision(2) << fixed << this->rebateAmount << endl;
    return output.str();

}
/*!
 * \brief executive::renew
 */
void executive::renew()
{
   member::addTT(125.00);
   member::addTTW(125.00);
}
