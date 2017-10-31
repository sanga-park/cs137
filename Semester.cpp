/*
CS 137 - Midterm Project 2017
Team EECS
*/

#include <iostream>
#include <iomanip>
#include "Semester.h"
using namespace std;

Semester::Semester(string semName, Date stDate, Date enDate) : semesterName(semName), semStartDate(stDate), semEndDate(enDate)
{
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
	//Fall 2017 (mm/dd/yyyy-mm/dd/yyyy) format
	getline(input, sem.semesterName); // takes semester name (string)
	input.ignore(); // ignore enter
	input >> setw(2) >> sem.semStartDate;
	input.ignore(); // ignore bar/enter
	input >> setw(2) >> sem.semEndDate;
	input.ignore();

	return input;
}
