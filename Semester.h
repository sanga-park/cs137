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
		Semester(string, Date, Date);
		~Semester();

		Semester& setSemesterName(string&);
		Semester& setSemStartDate(Date&);//has to be semester start date 
		Semester& setSemEndDate(Date&);
		string getSemesterName() const;
		Date getSemStartDate() const;
		Date getSemEndDate() const;
};

#endif SEMESTER_H