#include  "member.h"
/*!
 * \file member.cpp
 * \brief Source file for member class methods
 *
 * This file contains all of the definitions for the member class
 */
member::member() : name("Default Name"), type("Member"), id(-200), total(-200), totalwTax(-200)
{
}
member::~member(){}
member::member(string newName, double newId) : name(newName), type("Member"), id(newId), total(0), totalwTax(0)
{
}

member::member(string newName, string newType, double newId, double newTotal, Date newExprDate)
{
	this->id = newId;
	this->type = newType;
	this->name = newName;
	this->total = newTotal;
	totalwTax = 0; // place holder
	this->exprDate = newExprDate;
}
void member::setAll(string name, string type, double id, Date exprDate)
{
	this->id = id;
	this->type = type;
	this->name = name;
	this->exprDate = exprDate;

	total = 0;
	totalwTax = 0;
}
void member::setName(string newName)
{
	this->name = newName;
}

void member::setType(string newType)
{
	this->type = newType;
}

void member::setId(double newId)
{
	this->id = newId;
}

void member::setTotal(double newTotal)
{
	this->total = newTotal;
}

void member::setExprDate(Date exprDate)
{
	this->exprDate = exprDate;
}

string member::getName() const
{
	return this->name;
}

string member::getType() const
{
	return this->type;
}

double member::getId() const
{
	return this->id;
}

double member::getTotal() const
{
	return this->total;
}

double member ::getTotalwTax() const
{
    return this->totalwTax;
}

Date member::getExprDate() const
{
	return this->exprDate;
}

QString member::printMember() const {
    QString s;
    QTextStream ss(&s);
    string name2;
    ss.AlignLeft;
//	stringstream output;
    name2 = name;
    if(name.size() > 20){
        name2 = name.substr(0, 20) + "...";
    }
    ss << qSetFieldWidth(30) << QString::fromStdString(name2 + "\t\t");
    ss << qSetFieldWidth(15) << QString::fromStdString(this->type + "\t\t");
    ss << qSetFieldWidth(10) << QString::number(this->id) + "\t";
    ss << qSetFieldWidth(8) << QString::number(this->totalwTax, 'f', 2);
    ss << qSetFieldWidth(8) << QString::fromStdString("\t" + this->exprDate.DisplayDate());
//	output << this->name << endl;
//	output << this->type << endl;
//	output << fixed << setprecision(0) << this->id << endl;
//	output <<  fixed << setprecision(2) <<this->totalwTax << endl;
//	output << exprDate.DisplayDate() << endl;
//	return output.str();
    return s;
}

string member::saveMember() const
{
    stringstream output;
    output << this->name << endl;
    output << this->id << endl;
    output << this->type << endl;
    output <<this->exprDate.DisplayDate() << endl;


    return output.str();
}

void member::addTT(float a){
	this->total += a;
}
void member::addTTW(float a){
	this->totalwTax += a;
}
string member::printRebate()
{
    stringstream output;
    return output.str();

}

void member::renew()
{
    total += 45.00;
    totalwTax += 45.00;
}

void member::setTotalwTax(double total){
    this->totalwTax = total;
}
