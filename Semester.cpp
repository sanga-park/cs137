#include <iostream>
#include <iomanip>
#include "Semester.h"
using namespace std;

Semester::Semester(string semName, Date stDate, Date enDate)
{
	setSemesterName(semName);
	setSemStartDate(stDate);
	setSemEndDate(stDate);
}

Semester::~Semester()
{
	cout << "The semester has been reset." << endl;
}

Semester& Semester::setSemesterName(string& semName)
{
	semesterName == (semName != "" ? semesterName : "Default");
	return *this;
}

Semester& Semester::setSemStartDate(Date& stDate)
{
	semStartDate == (stDate != Date(0, 0, 0) ? semStartDate : Date(0, 0, 0));
	return *this;
}

Semester& Semester::setSemEndDate(Date& enDate)
{
	semEndDate == (enDate != Date(0, 0, 0) ? semEndDate : Date(0, 0, 0));
	return *this;
}

string Semester::getSemesterName() const
{
	return semesterName;
}

Date Semester::getSemStartDate() const
{
	return semStartDate;
}

Date Semester::getSemEndDate() const
{
	return semEndDate;
}

ostream &operator<<(ostream& output, const Semester &sem)
{
	//Semester: Fall 2017 (00/00/0000-00/00/0000)
	output << "Semester: " << sem.semesterName << " (" << sem.semStartDate << "-" << sem.semEndDate << ") " << endl;
	return output;
}

istream &operator>>(istream& input, Semester& sem)
{
	cout << "Please enter the semester name and press enter;\n" 
		 << "then input the semester duration in (mm/dd/yyyy-mm/dd/yyyy) format: \n";
	getline(input, sem.semesterName); // takes a string (containing spaces) 
	input.ignore(); // ignore enter
	input >> sem.semStartDate;
	input.ignore(); // ignore bar (-)
	input >> sem.semEndDate;

	return input;
}