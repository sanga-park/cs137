/*
CS 137 - Midterm Project 2017
Team EECS
*/

#include <iostream>
#include <iomanip>
using namespace std;
#include "Date.h"

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr)
{
	setDate(mn, dy, yr);
}

////////////////////////////////////////////////////////////////
/////////////////// GET SET FUNCTIONS //////////////////////////
////////////////////////////////////////////////////////////////
Date& Date::setDate(int mn, int dy, int yr)
{
	setMonth(mn);
	setDay(dy);
	setYear(yr);
	return *this;
}

Date& Date::setMonth(int mn)
{
	month = (mn >= 1 && mn <= 12) ? mn : 1;
	return *this;
}

Date& Date::setDay(int dy)
{
	day = (dy >= 1 && dy <= 31) ? dy : 1;
	return *this;
}

Date& Date::setYear(int yr)
{
	year = (yr >= 2001 && yr <= 2099) ? yr : 2017;
	return *this;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getYear() const
{
	return year;
}

//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
	static const int daysPerMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (testDay > 0 && testDay <= daysPerMonth[month])
	{
		return testDay;
	}

	//determine whether testDay is valid for a specific month
	if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
	{
		return testDay;
	}

	cout << "Invalid Day " << testDay << " was set to 1" << endl;
	return 1;  //keep data in valid state
}

////////////////////////////////////////////////////////////////
//////////////////////// OPERATORS /////////////////////////////
//////////////////////////////////////////////////////////////// 
ostream &operator << (ostream &output, const Date &date)
{
	output << setfill('0') << setw(2) << date.month << "/" << setw(2) << date.day << "/" << setw(2) << date.year;
	return output;
}

istream &operator >> (istream &input, Date &date)
{
	// check if it assepts 6 as if 06 was entered--->works

	// input is in MM/DD/YYYY format
	input >> setw(2) >> date.month;
	input.ignore(); // skip /
	input >> setw(2) >> date.day;
	input.ignore(); // skip /
	input >> setw(4) >> date.year;
	return input;
}

bool Date::operator > (const Date &right) const
{
	bool status = false;

	//compare year first -> only if the year is the same, then check the month -> and same for the day 
	//could've done with switch 
	if (year > right.year)
	{
		status = true;
	}
	else if (year == right.year)
	{
		if (month > right.month)
		{
			status = true;
		}
		else if (month == right.month)
		{
			if (day > right.day)
			{
				status = true;
			}
		}
	}
	return status;
}

void Date::operator = (const Date &right)
{
	month = right.month;
	day = right.day;
	year = right.year;
}

bool Date::operator < (const Date &right) const
{
	return !(operator >(right)); // it does work. bb
}

bool Date::operator == (const Date &right) const
{
	return ((month == right.month && day == right.day && year == right.year) ? true : false);
}

bool Date::operator != (const Date &right) const
{
	return !(operator ==(right));
}

bool Date::operator >= (const Date &right) const
{
	return (operator >(right) || operator ==(right) ? true : false);
}

bool Date::operator <= (const Date &right) const
{
	return (operator <(right) || operator ==(right) ? true : false);
}
