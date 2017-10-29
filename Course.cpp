#include <iostream>
#include <iomanip>
#include "Course.h"
using namespace std;

Course::Course(string csNum, string csName, string mtDays, double unt, Date stDate, Date enDate, Time stTime, Time enTime)
	  :courseNum(csNum), courseName(csName), meetDays(mtDays), unit(unt), startDate(stDate), endDate(enDate), startTime(stTime), endTime(enTime)
{
}

//destructor
Course::~Course()
{
	cout << "The destructor for course class has been called." << endl;
}


///////////////////////////////////////////get functions
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

///////////////////////////////////////////set functions
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



//remove & replace function 
void Course::remove(Course* cs)
{
	Course* defaultCourse = nullptr; //initialized
	cs = defaultCourse;

}

void Course::replace(Course* cs, int sel)
{
	cs[sel - 1].courseNum = cs[sel].courseNum;
	//and so on...
}

void Course::operator= (const Course& right) //this will be copied to Courses
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



//////////////////////////////////////////// iostream operators
ostream &operator << (ostream &output, const Course& course)//, const Date& date, const Time& time) //ohh!!
{
	output << "Course Info: " << course.courseNum << " -- " << course.courseName << endl
		<< "Number of Units: " << setprecision(2) <<setfill('0') << course.unit << endl //how to make it work in 0.00 format
		<< "Course Dates: " << course.startDate << " - " << course.endDate << endl 
		<< "Meeting Days: " << course.meetDays << endl
		<< "Meeting Time: " << course.startTime << " - " << course.endTime << endl 
		// to use Time - operator, the variables shouldn't be private -- reason why using get functions only in here. 
		<< "Daily Duration: " << course.getEndTime() - course.getStartTime() << endl;
	return output;
}






/* DON'T NEED THIS PART, I'm just saving it in case and check if it still works (out of curiousity) 
istream &operator >> (istream &input, Course& course)
{
	cout << "Course Info: ";
	input >> course.courseNum;
	input.ignore(); // ignore a space
	cout << "# of Units: ";
	input >> course.unit;
	input.ignore();
	cout << "Course Dates in mm/dd/yyyy-mm/dd/yyyy format:";
	input >> course.startDate;
	input.ignore(); // ignore a bar
	input >> course.getEndDate;
	input.ignore();
	cout << "Meeting Days: ";
	input >> course.meetDays;
	input.ignore();
	cout << "Meeting Times: ";

	return input;
}*/