#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H
#include <string>
#include <iostream>
#include "Semester.h"
using namespace std;

enum DateStatus { clear = 5, startD = 3, endD = 4, both = 2};

class CourseSchedule
{
	friend ostream &operator<<(ostream &, const CourseSchedule &);

	private:
		static int numCourses;
		int maxSize;
		Course* Courses;
		//course(string, string, string, double, Date, Date, Time, Time);
		//I don't think we need additional course data type as private member. 

		string sname; // student name
		Semester smester;
		Date startDate;
		Date endDate;
		int checkDates(Semester, Date, Date);      //How do we call course private member variables?

	public:
		CourseSchedule(string, Semester, int);
		~CourseSchedule();
		string getStudentName() const;
		Semester getSemester() const;
		int getnumCourse() const;
		void setStudentName(string);
		void addCourse(Course&, Semester, Date, Date);
};

#endif COURSESHEDULE_H
