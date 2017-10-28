#include <iostream>
#include <iomanip>
using namespace std;
#include "Time.h"

void Time::convertToUniversal()
{
	if  (amorpm == "PM")
	{
		hour += 12;
	}
	else;

	amorpm = "";
}

double Time::operator-(Time& classTime)
{
	convertToUniversal();
	classTime.convertToUniversal();

	double hourDif;
	double minuteDif;

	if (hour >= classTime.hour)
	{
		if (minute >= classTime.minute)
		{
			hourDif = hour - classTime.hour;
			minuteDif = minute - classTime.minute;
		}
		else
		{
			hourDif = hour - 1 - classTime.hour;
			minuteDif = minute + 60 - classTime.minute;
		}
	}
	else
	{
		if (minute <= classTime.minute)
		{
			hourDif = classTime.hour - hour;
			minuteDif = classTime.minute - minute;
		}
		else
		{
			hourDif = classTime.hour - 1 - hour;
			minuteDif = classTime.minute + 60 - minute;
		}
	}

	return hourDif + (minuteDif / 60);
}

ostream& operator<<(ostream& output, const Time& classTime)
{
	output << ((classTime.hour == 0 || classTime.hour == 12) ? 12 : classTime.hour % 12) << ":"
		<< setfill('0') << setw(2) << classTime.minute << ":"
		<< setw(2) << ((classTime.hour) < 12 ? "AM" : "PM");
	return output;
}

istream& operator>>(istream& input, Time& classTime)
{
	input >> classTime.hour;
	input.ignore();
	input >> classTime.minute;
	input.ignore();
	input >> classTime.amorpm;
	return input;
	// default times?
}

Time::Time(int hour, int minute)
{
	setTime(hour, minute);
}

Time& Time::setTime(int hour, int minute)
{
	setHour(hour);
	setMinute(minute);
	return* this;
}

Time& Time::setHour(int h)
{
	hour = (h >= 0 && h < 24) ? h : 0;  
	return* this;
}

Time& Time::setMinute(int m)
{
	minute = (m >= 0 && m < 24) ? m : 0;  
	return* this;
}

int Time::getHour() const 
{
	return hour;
}

int Time::getMinute() const 
{
	return minute;
}

void Time::printUniversal()const 
{
	cout << setfill('0') << setw(2) << hour << ":"
		<< setw(2) << minute << ":" << endl;
}

void Time::printStandard()const 
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
		<< setfill('0') << setw(2) << minute << ":"
		<< setw(2) << (hour < 12 ? "AM" : "PM") << endl;
}