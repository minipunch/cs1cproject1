#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include<iomanip>
using namespace std;

#ifndef DATE_H_
#define DATE_H_
/*!
 * \brief The Date class
 *
 * This Class keeps track of a date
 */

class Date
{
public:

	/***************************************************
	 * CONSTRUCTORS & DESTRUCTOR
	 **************************************************/
    /*!
     * \brief Default Constructor
     *
     * Initializes date to current date
     */
	Date();

    /*!
     * \brief Non-default constructor
     *
     * Create a pre-initialized date.
     * \param month new month
     * \param day   new day
     * \param year  new year
     */
	Date(unsigned short month,
			unsigned short day,
			unsigned short year);

	~Date();

	/****************************************************
	 * MUTATORS
	 ***************************************************/
    /*!
     * \brief Set the Date
     *
     *
     * Set month day and year of a date object
     * \param month  new month
     * \param day    new day
     * \param year   new year
     */
	void SetDate(unsigned short month,
			unsigned short day,
			unsigned short year);

    /*!
     * \brief Gets a Date
     *
     *  Returns a date to be used elsewhere
     *
     * \param month month to return
     * \param day day to return
     * \param year year to return
     */
	void GetDate(unsigned short &month,
			unsigned short &day,
			unsigned short &year) const;

    /*!
     * \brief Gets the year
     * \return the year
     */
	unsigned short GetYear()  const;
    /*!
     * \brief Gets the month
     * \return the month
     */
	unsigned short GetMonth() const;
    /*!
     * \brief Gets the day
     * \return the day
     */
	unsigned short GetDay()   const;

    /*!
     * \brief Displays a Date
     * \return the date to display
     */
	string DisplayDate() const;
    /*!
     * \brief compares 2 dates
     *
     * Compares 2 dates for uses in other parts of the program
     * \param d1 First date
     * \param d2 Second date
     * \return T/F whether or not the dates were equal
     */
	friend bool operator == (Date & d1, Date & d2);

private:
    /*!
     * \brief GetDaysInMonth
     *
     * Gets the days in month
     * \param month
     * \param year
     * \return
     */
	unsigned short GetDaysInMonth(unsigned short month,
			unsigned short year) const;

	bool IsLeapYear(unsigned short year) const;



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


    unsigned short dateMonth; //!< the month for a date
    unsigned short dateDay;   //!< the day for a date
    unsigned short dateYear;  //!< the year for a date


   /*!
    * \file date.h
    * \brief  Header for date class
    *
    * This file contains all of the declarations of the date class
    */

};




#endif /* DATE_H_ */
