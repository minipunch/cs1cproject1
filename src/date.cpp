#include "header.h"
#include "date.h"

date::date() {
	month = 1;
	day = 1;
	year = 1995;
}

date::date(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}

void date::printDate() const{
	std::cout << "Hired: " << month << "/" << day << "/" << year << std::endl;
}

void date::setMonth(int m) {
	this->month = m;
}

void date::setDay(int d) {
	this->day = d;
}

void date::setYear(int y) {
	this->year = y;
}


did this one work

