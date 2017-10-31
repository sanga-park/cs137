/*
CS 137 - Midterm Project 2017
Team EECS
*/

#ifndef SEMESTER_H
#define SEMESTER_H

#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

class Semester
{
	friend ostream &operator<<(ostream &, const Semester &);
	friend istream &operator>>(istream &, Semester &);

private:
	string semesterName;
	Date semStartDate;
	Date semEndDate;

public:
	Semester(string ="Semetser Name", Date =(1,1,2017), Date =(1,1,2017));

	Semester& setSemesterName(string&);
	Semester& setSemStartDate(Date&);
	Semester& setSemEndDate(Date&);
	string getSemesterName() const;
	Date getSemStartDate() const;
	Date getSemEndDate() const;
};

#endif SEMESTER_H
