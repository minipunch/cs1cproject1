#include  "member.h"

member::member()
{
	name  = 'N';
	type  = 'N';
	id    = 00000;
	total = 0;
	Date();
}

member::member(string newName, double newId)
{
	this->id = newId;
	this->name = newName;
	type  = 'N';
	total = 0;
	Date();
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
	exprDate.SetDate(newMonth, newDay, newYear);
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
