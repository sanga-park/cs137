//Time Class Definition with const member functions
#ifndef TIME_H
#define TIME_H
#include <string>
#include <iostream>
using namespace std;

class Time
{
	friend ostream& operator<<(ostream&, const Time &);
	friend istream& operator>>(istream&, Time &);

private:
	int hour;  //0-23 (24 hour clock format)
	int minute; //0-59
	string amorpm;
	void convertToUniversal();

public:
	Time(int = 0, int = 0);

	Time& setTime(int, int);
	Time& setHour(int);
	Time& setMinute(int);
	int getHour() const;
	int getMinute() const;
	void printUniversal() const;
	void printStandard() const;
	double operator-(Time&);
};

#endif