#include  "member.h"

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

Date member::getExprDate() const
{
	return this->exprDate;
}

string member::printMember(){

	stringstream output;
	output << left << "|" << setw(30) << this->name << "|   ";
	output << setw(8) << fixed << setprecision(0) << this->id << "|  ";
	output << setw(10) << this->type << "|   ";
	output << setw(14) << exprDate.DisplayDate() << "| ";
	output << right << setw(10) << /*doubleToString(this->total)*/ "12345.67" << "|";
	output << right << setw(12) << doubleToString(this->totalwTax) << "|";
	return output.str();
}

void member::addTT(float a){
	this->total += a;
}
void member::addTTW(float a){
	this->totalwTax += a;
}

string member::doubleToString(double num){
	stringstream numString;
	numString << "$" << fixed << setprecision(2) << num;
	return numString.str();
}
