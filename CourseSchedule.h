#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H
#include <string>
#include <iostream>
#include "Semester.h"
using namespace std;

enum DateStatus { clear = 5, startD = 3, endD = 4, both = 2 };

class CourseSchedule
{
	friend ostream &operator<<(ostream &, const CourseSchedule &);

private:
	int numCourses; //doesn't need to be static because we will have only one class for CourseSchedule...
	int maxSize;
	Course* Courses;

	string sname; // student name
	Semester smester;
	Date startDate;
	Date endDate;
	int checkDates(Semester, Date, Date);

public:
	CourseSchedule(string, Semester, int);
	~CourseSchedule();
	string getStudentName() const;
	Semester getSemester() const;
	int getnumCourse() const;
	void setStudentName(string);
	void addCourse(Course&, Semester, Date, Date);
	void removeCourse();
};

#endif COURSESHEDULE_H