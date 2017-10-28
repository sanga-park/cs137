#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H
#include <string>
#include <iostream>
#include "Semester.h"
#include "Date.h"
using namespace std;

class CourseSchedule
{
private:
	static int numCourses;
	Course* Courses;
	Course(string, string, string, double, Date, Date, Time, Time);

	int maxSize;
	string sname; // student name
	Semester smester;
	Date startDate;
	Date endDate;
	void checkDates(Semester, Date, Date);      //How do we call course private member variables?

public:
	CourseSchedule(string, Semester, int);
	~CourseSchedule();
	string getStudentName() const;
	Semester getSemester() const;
	int getnumCourse() const;
	void setStudentName(string);
};

#endif COURSESHEDULE_H