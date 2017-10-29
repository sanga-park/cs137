#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Course
{
	friend ostream &operator<<(ostream &, const Course &);

	private:
		string courseNum;
		string courseName;
		string meetDays;
		double unit;
		Date startDate;
		Date endDate;
		Time startTime;
		Time endTime;

	public:
		//by adding member initializers we don't need the default constructor 
		Course(string ="", string ="", string ="", double =0.0, Date =(0,0,0), Date =(0,0,0), Time =(0,0,0), Time=(0,0,0));
		~Course();
		string getCourseNum() const;
		string getCourseName() const;
		string getMeetDays() const;
		double getUnit() const;
		Date getStartDate() const;
		Date getEndDate() const;
		Time getStartTime() const;
		Time getEndTime() const;

		void remove(Course*); //test
		void replace(Course*, int); //test

		Course& setCourseNum(string&);
		Course& setCourseName(string&);
		Course& setMeetDays(string&);
		void setUnit(double);
		Course& setStartDate(Date&);
		Course& setEndDate(Date&);
		Course& setStartTime(Time&);
		Course& setEndTime(Time&);

		void operator= (const Course& cs);
};

#endif