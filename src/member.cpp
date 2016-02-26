#include  "member.h"

member::member() : name("Default Name"), type("Member"), id(-200), total(-200)
{
}
member::~member(){}
member::member(string newName, double newId) : name(newName), type("Member"), id(newId), total(0)
{
}

member::member(string newName, string newType, double newId, double newTotal, Date newExprDate)
{
	this->id = newId;
	this->type = newType;
	this->name = newName;
	this->total = newTotal;
	this->exprDate = newExprDate;
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

void member::setExprDate(int newMonth, int newDay, int newYear)
{
	this->exprDate.SetDate(newMonth, newDay, newYear);
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

void member::printMember() const {
	cout << this->name << endl;
	cout << this->type << endl;
	cout << this->id << endl;
	cout << this->total << endl;
	cout << exprDate.DisplayDate();
}
