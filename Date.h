#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include "Time.h"

using namespace std;

class Date
{
	friend ostream &operator<<(ostream &, const Date &);
	friend istream &operator>>(istream &, Date &);
        private:
                int month; //1-12
                int day; //1-31 depending on month
                int year; //any year

				const Time StartTime;
				const Time EndTime; 
                
                //utility function to check if day is proper for month and year
                int checkDay(int) const;

        public:
               Date(int = 1, int = 1, int = 2017);
               //~Date();
			   //Date(const Date&); //copy constructor -> memberwise assignment 
			   Date& setDate(int, int, int);

			   //add get/set member variable functions
			   Date& setMonth(int);
			   Date& setDay(int);
			   Date& setYear(int);
			   int getMonth() const;
			   int getDay() const;
			   int getYear() const;

			   void operator= (const Date &);
			   bool operator>(const Date&) const;
			   bool operator<(const Date&) const;
			   bool operator==(const Date&) const;
			   bool operator!=(const Date&) const;
			   bool operator>=(const Date&) const;
			   bool operator<=(const Date&) const;
};

#endif