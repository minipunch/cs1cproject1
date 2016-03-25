#include  "member.h"
/*!
 * \brief member::member
 */
member::member() : name("Default Name"), type("Member"), id(-200), total(-200), totalwTax(-200)
{
}
/*!
 * \brief member::~member
 */
member::~member(){}
/*!
 * \brief member::member
 * \param newName
 * \param newId
 */
member::member(string newName, double newId) : name(newName), type("Member"), id(newId), total(0), totalwTax(0)
{
}
/*!
 * \brief member::member
 * \param newName
 * \param newType
 * \param newId
 * \param newTotal
 * \param newExprDate
 */
member::member(string newName, string newType, double newId, double newTotal, Date newExprDate)
{
	this->id = newId;
	this->type = newType;
	this->name = newName;
	this->total = newTotal;
	totalwTax = 0; // place holder
	this->exprDate = newExprDate;
}
/*!
 * \brief member::setAll
 * \param name
 * \param type
 * \param id
 * \param exprDate
 */
void member::setAll(string name, string type, double id, Date exprDate)
{
	this->id = id;
	this->type = type;
	this->name = name;
	this->exprDate = exprDate;

	total = 0;
	totalwTax = 0;
}

/*!
/*! * \brief member::setName
/*! * \param newName
/*! */
void member::setName(string newName)
{
	this->name = newName;
}
/*!
 * \brief member::setType
 * \param newType
 */
void member::setType(string newType)
{
	this->type = newType;
}
/*!
 * \brief member::setId
 * \param newId
 */
void member::setId(double newId)
{
	this->id = newId;
}
/*!
 * \brief member::setTotal
 * \param newTotal
 */
void member::setTotal(double newTotal)
{
	this->total = newTotal;
}
/*!
 * \brief member::setExprDate
 * \param exprDate
 */
void member::setExprDate(Date exprDate)
{
	this->exprDate = exprDate;
}
/*!
 * \brief member::getName
 * \return
 */
string member::getName() const
{
	return this->name;
}
/*!
 * \brief member::getType
 * \return
 */
string member::getType() const
{
	return this->type;
}
/*!
 * \brief member::getId
 * \return
 */
double member::getId() const
{
	return this->id;
}
/*!
 * \brief member::getTotal
 * \return
 */
double member::getTotal() const
{
	return this->total;
}
/*!
 * \brief member::getTotalwTax
 * \return
 */
double member ::getTotalwTax() const
{
    return this->totalwTax;
}
/*!
 * \brief member::getExprDate
 * \return
 */
Date member::getExprDate() const
{
	return this->exprDate;
}
/*!
 * \brief member::printMember
 * \return
 */
string member::printMember() const {

	stringstream output;
	output << this->name << endl;
	output << this->type << endl;
	output << fixed << setprecision(0) << this->id << endl;
	output <<  fixed << setprecision(2) <<this->totalwTax << endl;
	output << exprDate.DisplayDate() << endl;
	return output.str();
}
/*!
 * \brief member::saveMember
 * \return
 */
string member::saveMember() const
{
    stringstream output;
    output << this->name << endl;
    output << this->id << endl;
    output << this->type << endl;
    output <<this->exprDate.DisplayDate() << endl;


    return output.str();
}
/*!
 * \brief member::addTT
 * \param a
 */
void member::addTT(float a){
	this->total += a;
}
/*!
 * \brief member::addTTW
 * \param a
 */
void member::addTTW(float a){
	this->totalwTax += a;
}
/*!
 * \brief member::printRebate
 * \return
 */
string member::printRebate()
{
    stringstream output;
    return output.str();

}
/*!
 * \brief member::renew
 */
void member::renew()
{
    total += 45.00;
    totalwTax += 45.00;
}
/*!
 * \brief member::setTotalwTax
 * \param total
 */
void member::setTotalwTax(double total){
    this->totalwTax = total;
}
