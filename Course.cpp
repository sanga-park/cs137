/*
CS 137 - Midterm Project 2017
Team EECS
*/

#include <iostream>
#include <iomanip>
#include "Course.h"
using namespace std;

Course::Course(string csNum, string csName, string mtDays, double unt, Date stDate, Date enDate, Time stTime, Time enTime)
	:courseNum(csNum), courseName(csName), meetDays(mtDays), unit(unt), startDate(stDate), endDate(enDate), startTime(stTime), endTime(enTime)
{
}

Course::~Course()
{
	cout << "The destructor for course class has been called." << endl;
}

////////////////////////////////////////////////////////////////
/////////////////// GET SET FUNCTIONS //////////////////////////
////////////////////////////////////////////////////////////////
string Course::getCourseNum() const
{
	return courseNum;
}

string Course::getCourseName() const
{
	return courseName;
}

string Course::getMeetDays() const
{
	return meetDays;
}

double Course::getUnit() const
{
	return unit;
}

Date Course::getStartDate() const
{
	return startDate;
}

Date Course::getEndDate() const
{
	return startDate;
}

Time Course::getStartTime() const
{
	return startTime;
}

Time Course::getEndTime() const
{
	return endTime;
}

Course& Course::setCourseNum(string& csNum)
{
	courseNum = (csNum != "" ? csNum : "Course Number");
	return *this;
}

Course& Course::setCourseName(string& csName)
{
	courseName = (csName != "" ? csName : "Course Name");
	return *this;
}

Course& Course::setMeetDays(string& meets)
{
	for (int i = 0; i < meetDays.length() ; i++)
	{
		toupper(meetDays[i]);
	}
	meetDays = (meets != "" ? meets : "MTWTF");
	return *this;
}

void Course::setUnit(double unt)
{
	unit = (unt >= 0 ? unt : 0);
}

Course& Course::setStartDate(Date& stDate)
{
	startDate = stDate;
	return *this;
}

Course& Course::setEndDate(Date& enDate)
{
	endDate = enDate;
	return *this;
}

Course& Course::setStartTime(Time& stTime)
{
	startTime = stTime;
	return *this;
}

Course& Course::setEndTime(Time& enTime)
{
	endTime = enTime;
	return *this;
}

////////////////////////////////////////////////////////////////
////////////// COURSE REMOVE & REPLACE FUNCTION  ///////////////
//////////////////////////////////////////////////////////////// 
void Course::remove(Course* cs)
{
	Course* defaultCourse = nullptr; //initialize
	cs = defaultCourse;
}

void Course::replace(Course* cs, int sel)
{
	// move every variable(information) in one element to one to the left in the array 
	// Since the memberwise assignment for pointer variables are prohibited
	// we assigned each variable individually.

	// cs[sel - 1] = cs[sel];
	cs[sel - 1].courseNum = cs[sel].courseNum;
	cs[sel - 1].courseName = cs[sel].courseName;
	cs[sel - 1].meetDays = cs[sel].meetDays;
	cs[sel - 1].unit = cs[sel].unit;
	cs[sel - 1].startDate = cs[sel].startDate;
	cs[sel - 1].endDate = cs[sel].endDate;
	cs[sel - 1].startTime = cs[sel].startTime;
	cs[sel - 1].endTime = cs[sel].endTime;
}

////////////////////////////////////////////////////////////////
//////////////////////// OPERATORS /////////////////////////////
//////////////////////////////////////////////////////////////// 

void Course::operator= (const Course& right)
{
	courseNum = right.courseNum;
	courseName = right.courseName;
	meetDays = right.meetDays;
	unit = right.unit;
	startDate = right.startDate;
	endDate = right.endDate;
	startTime = right.startTime;
	endTime = right.endTime;
}

ostream &operator << (ostream &output, const Course& course)
{
	output << "Course Info: " << course.courseNum << " -- " << course.courseName << endl
		<< "Number of Units: " << fixed << setprecision(2) << setfill('0') << course.unit << endl 
		<< "Course Dates: " << course.startDate << " - " << course.endDate << endl
		<< "Meeting Days: " << course.meetDays << endl
		<< "Meeting Time: " << course.startTime << " - " << course.endTime << endl
		<< "Daily Duration: " << course.getEndTime() - course.getStartTime() << "hr" << endl;
	return output;
}
