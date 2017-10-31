/*
CS 137 - Midterm Project 2017
Team EECS
*/

#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H
#include <string>
#include <iostream>
#include "Semester.h"
using namespace std;

enum DateStatus { CLEAR = 5, STARTD = 3, ENDD = 4, BOTH = 2 };

class CourseSchedule
{
	friend ostream &operator<<(ostream &, const CourseSchedule &);

private:
	int numCourses;
	int maxSize;
	Course* Courses;

	string sname;		// student name
	Semester smester;	// semester name 
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
