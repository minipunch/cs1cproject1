#pragma once

class date {
	int month;
	int day;
	int year;
public:
	date();
	date(int m, int d, int y);
	void setMonth(int m);
	int getMonth() const;
	void setDay(int d);
	int getDay() const;
	void setYear(int y);
	int getYear() const;
	void printDate() const;

};
