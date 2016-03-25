/*************************************************************************
 * AUTHOR     : Nick Sidaris
 * STUDENT ID : 385623
 * ASSI #3    : Inheritance
 * Class      : CS1C
 * SECTION    : M/W 2:00pm
 * DUE DATE   : 2/10/16
 ************************************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include<iomanip>
using namespace std;

#ifndef DATE_H_
#define DATE_H_
/************************************************************************
 * Date Class
 * ______________________________________________________________________
 * This class keeps track of 3 values that represent a date. The date can
 * be set an validated. I made this back in CS1B and am reusing it. That
 * is why the documentation is different(sorry!)
 *
 ***********************************************************************/
class Date
{
public:

	/***************************************************
	 * CONSTRUCTORS & DESTRUCTOR
	 **************************************************/
	Date();

	//uses private utility methods
	Date(unsigned short month,
			unsigned short day,
			unsigned short year);

	~Date();

	/****************************************************
	 * MUTATORS
	 ***************************************************/
	void SetDate(unsigned short month,
			unsigned short day,
			unsigned short year);

	/****************************************************
	 * ACCESSORS
	 ***************************************************/
	void GetDate(unsigned short &month,
			unsigned short &day,
			unsigned short &year) const;

	unsigned short GetYear()  const;
	unsigned short GetMonth() const;
	unsigned short GetDay()   const;

	string DisplayDate() const;
	friend bool operator == (Date & d1, Date & d2);

private:

	/****************************************************
	 * UTILITIES METHODS
	 ***************************************************/

	unsigned short GetDaysInMonth(unsigned short month,
			unsigned short year) const;

	bool IsLeapYear(unsigned short year) const;

	/****************************************************
	 * VALIDATE METHODS
	 ***************************************************/

	//validates the month
	bool ValidateMonth(unsigned short month) const;

	// checks if day is valid takes year into consideration
	bool ValidateDay(unsigned short month,
			unsigned short day,
			unsigned short year) const;

	//Validates the year is between 1900 and current year
	bool ValidateYear(unsigned short year) const;

	// uses methods above to validate a given date
	//checks against current day
	bool ValidateDate(unsigned short month,
			unsigned short day,
			unsigned short year) const;

	/****************************************************
	 * ATTRIBUTES
	 ***************************************************/
	unsigned short dateMonth; //CALC - Month
	unsigned short dateDay;   //CALC - day
	unsigned short dateYear;  //CALC - year
};




#endif /* DATE_H_ */
