#include <iostream>
#include <iomanip>
#include "Semester.h"
using namespace std;

Semester::Semester(string semName, Date stDate, Date enDate) : semesterName(semName), semStartDate(stDate), semEndDate(enDate)
{
}

Semester::~Semester()
{
	cout << "The destructor for semester class has been called." << endl;
}

Semester& Semester::setSemesterName(string& semName)
{
	semesterName = (semName != "" ? semName : "Default");
	return *this;
}

Semester& Semester::setSemStartDate(Date& stDate)
{
	//since the validation for date is done when date instance was created -- don't need to verify again here
	//memberwise assignment applied here --see if there's any problem 
	semStartDate = stDate;
	return *this;
}

Semester& Semester::setSemEndDate(Date& enDate)
{
	semEndDate = enDate;
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
	//Fall 2017 (mm/dd/yyyy-mm/dd/yyyy) format
	output << sem.semesterName << " (" << sem.semStartDate << "-" << sem.semEndDate << ") " << endl;
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