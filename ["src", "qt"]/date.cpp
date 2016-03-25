#include "date.h"
/***************************************************
 * CONSTRUCTORS & DESTRUCTOR
 **************************************************/

/****************************************************************
 * date();
 * Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ***************************************************************/
Date::Date()
{
	time_t now;
	tm *currentTime;

	now = time(NULL);
	currentTime = localtime(&now);


	dateMonth = currentTime->tm_mon + 1;
	dateDay =  currentTime->tm_mday;
	dateYear = 1900 + currentTime->tm_year;
}
/****************************************************************
 * Date(unsigned short month,
			unsigned short day,
			unsigned short year);
 * Constructor; Initialize class attributes
 * Parameters: unsigned short month //month
 *             unsigned short day   //day
 *             unsigned short year  //year
 * Return: none
 ***************************************************************/
Date::Date(unsigned short month,
		unsigned short day,
		unsigned short year)
{

	if(ValidateDate(month, day, year))
	{
		dateMonth = month;
		dateDay = day;
		dateYear = year;
	}
	else
	{
		cout << "\nDate is invalid" << endl;
	}
}
/****************************************************************
 * ~date();
 * Destructor;
 * Parameters: none
 * Return: none
 ***************************************************************/

Date::~Date()
{}

/****************************************************
 * MUTATORS
 ***************************************************/

/****************************************************************
 * void SetDate(unsigned short month,
			unsigned short day,
			unsigned short year);
 * Parameters: unsigned short month //month
 *             unsigned short day   //day
 *             unsigned short year  //year
 * Return: none
 ***************************************************************/
void Date::SetDate(unsigned short month,
		unsigned short day,
		unsigned short year)
{
	if(ValidateDate(month, day, year))
	{
		dateMonth = month;
		dateDay = day;
		dateYear = year;
	}
	else
	{
		cout << "\nThat date is invalid" << endl;
	}

}
/****************************************************
 * ACCESSORS
 ***************************************************/

/****************************************************************
 * void GetDate(unsigned short &month,
			unsigned short &day,
			unsigned short &year) const;
 * Accessor; Gets the date
 * Parameters: unsigned short month //month
 *             unsigned short day   //day
 *             unsigned short year  //year
 * Return: none
 ***************************************************************/
void Date::GetDate(unsigned short &month,
		unsigned short &day,
		unsigned short &year) const
{
	month = dateMonth;
	day = dateDay;
	year = dateYear;
}

/****************************************************************
 * unsigned short GetYear()  const;
 * Accessor; Gets the year
 * Parameters: none
 * Return: year
 ***************************************************************/
unsigned short Date::GetYear() const
{
	return dateYear;
}

/****************************************************************
 * unsigned short GetMonth() const;
 * Accessor; Gets the month
 * Parameters: none
 * Return: month
 ***************************************************************/
unsigned short Date::GetMonth() const
{
	return dateMonth;
}

/****************************************************************
 * unsigned short GetDay()  const;
 * Accessor; Gets the day
 * Parameters: none
 * Return: day
 ***************************************************************/
unsigned short Date::GetDay() const
{
	return dateDay;
}

/****************************************************************
 * string DisplayDate() const;
 * Accessor; Displays the date
 * Parameters: none
 * Return: none
 ***************************************************************/
string Date::DisplayDate() const
{
	ostringstream output;
	if(dateMonth < 10)
	{
		output << 0;
	}
	output << dateMonth << "/";
	if(dateDay < 10)
	{
		output << 0;
	}
	output << dateDay << "/" << dateYear;
	return output.str();


}
/****************************************************
 * UTILITIES METHODS
 ***************************************************/

/****************************************************************
 * unsigned short GetDaysInMonth(unsigned short month,
			unsigned short year) const;
 * Utiltiy; Gets days in month
 * Parameters: unsigned short month //month
 *             unsigned short year  //year
 * Return: days in month
 ***************************************************************/
unsigned short Date::GetDaysInMonth(unsigned short month,
		unsigned short year) const
{
	int daysInMonth;
	//finds what the month is
	switch(month-1)
	{
	case 0: //jan
		daysInMonth = 31;
		break;
	case 1: //feb
		if(IsLeapYear(year))
		{
			daysInMonth = 29;
		}
		else
		{
			daysInMonth = 28;
		}
		break;
	case 2: //mar
		daysInMonth = 31;
		break;
	case 3: //apr
		daysInMonth = 30;
		break;
	case 4: //may
		daysInMonth = 31;
		break;
	case 5: //June
		daysInMonth = 30;
		break;
	case 6: //July
		daysInMonth = 31;
		break;
	case 7: //Aug
		break;
	case 8: //Sept
		daysInMonth = 30;
		break;
	case 9: //Oct
		daysInMonth = 31;
		break;
	case 10: //Nov
		daysInMonth = 30;
		break;
	case 11: //Dec
		daysInMonth = 31;
		break;
	}
	return daysInMonth;
}

/****************************************************************
 * bool IsLeapYear(unsigned short year) const;
 * utility; Checks to see if year is a leap year
 * Parameters: unsigned short year  //year
 * Return: t/f depending if year is leap year
 ***************************************************************/
bool Date::IsLeapYear(unsigned short year) const
{
	bool result;

	result = false;

	if(year%400 == 0 || (year%4 == 0 && year%100 !=0))
	{
		result = true;
	}
	return result;
}

/****************************************************
 * VALIDATE METHODS
 ***************************************************/
/****************************************************************
 * bool ValidateMonth(unsigned short month) const;
 * utility; Checks to see if the month is valid
 * Parameters: unsigned short month  //month
 * Return: t/f depending on if month is valid
 ***************************************************************/
bool Date::ValidateMonth(unsigned short month) const
{
	bool valid;
	valid = true;


	if(month < 1 || month > 12)
	{
		valid = false;
	}

	return valid;
}

/****************************************************************
 * bool ValidateDay(unsigned short day) const;
 * utility; Checks to see if the month is valid
 * Parameters: unsigned short day  //day
 * Return: t/f depending on if day is valid
 ***************************************************************/
bool Date::ValidateDay(unsigned short month, unsigned short day,
		unsigned short year) const
{
	bool valid;
	unsigned short maxDay;
	valid = true;


	maxDay = GetDaysInMonth(month, year);

	if(day < 1 || day > maxDay)
	{
		valid = false;
	}

	return valid;
}

/****************************************************************
 * bool ValidateYear(unsigned short year) const;
 * utility; Checks to see if the year is valid
 * Parameters: unsigned short year  //year
 * Return: t/f depending on if year is valid
 ***************************************************************/
bool Date::ValidateYear(unsigned short year) const
{
	bool valid;
	time_t now;
	tm *currentTime;
	unsigned short currentYear;
	valid = true;


	now = time(NULL);
	currentTime = localtime(&now);

	currentYear = 1900 + currentTime->tm_year;
	if(year < 1900 || year > currentYear)
	{
		valid = false;
	}

	return valid;
}

/****************************************************************
 *bool ValidateDate(unsigned short month,
					  unsigned short day,
					  unsigned short year) const;

 * utility; Checks to see if the date is valid
 * Parameters: unsigned short month //month
 *             unsigned short day   //day
 *             unsigned short year  //year
 * Return: t/f depending on if date is valid
 ***************************************************************/
bool Date::ValidateDate(unsigned short month, unsigned short day,
		unsigned short year) const
{

	return(ValidateMonth(month) &&
			ValidateDay(month, day, year) &&
			ValidateYear(year));
}

 bool operator == (Date & d1, Date & d2)
{
	bool isEqual = false;

	if(d1.dateDay == d2.dateDay &&
			d1.dateMonth == d2.dateMonth &&
			d1.dateYear == d2.dateYear)
	{
		isEqual = true;
	}

	return isEqual;
}

