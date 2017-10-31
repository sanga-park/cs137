/*
CS 137 - Midterm Project 2017
Team EECS
*/

#include "CourseSchedule.h"

CourseSchedule::CourseSchedule(string studentName, Semester semest, int num) : sname(studentName), smester(semest), maxSize(num)
{
	numCourses = 0;
	Courses = new Course[maxSize];
}

CourseSchedule::~CourseSchedule()
{
	numCourses = 0;
	maxSize = 0;
	//cout << "\nDestructor for CourseSchedule has been called. " << endl;
	delete[] Courses;
}

string CourseSchedule::getStudentName() const
{
	return sname;
}

Semester CourseSchedule::getSemester() const
{
	return smester;
}

int CourseSchedule::getnumCourse() const
{
	return numCourses;
}

void CourseSchedule::setStudentName(string sn)
{
	sname = sn;
}

////////////////////////////////////////////////////////////////
//////////////////// UTILITY FUNCTION //////////////////////////
////////////////////////////////////////////////////////////////
int CourseSchedule::checkDates(Semester sem, Date sDate, Date eDate)
{
	// counter for start or end dates if they satisfy the semester duration 
	int sCnt = 0;
	int eCnt = 0;

	// start  end       o:within 
	//  o      o  --5 -->CLEAR
	//  x      o  --3 -->STARTD
	//  o      x  --4 -->ENDD
	//  x      x  --2 -->BOTH
	sCnt = ((sem.getSemStartDate() <= sDate) ? 4 : 2);
	eCnt = ((sem.getSemEndDate() >= eDate) ? 1 : 0);

	return sCnt + eCnt;
}

void CourseSchedule::addCourse(Course& cou, Semester sem, Date sDate, Date eDate)
{
	if (numCourses <= maxSize)
	{
		int status = checkDates(sem, sDate, eDate);

		//allow adding a course only when the dates are within the semester duration
		if (status == CLEAR)
		{
			Courses[numCourses] = cou;
			numCourses++;
			cout << "\n\nThe class has been successfully added to your schedule." << endl;
		}
		else if (status == STARTD)
		{
			cout << "\nClass start date is over the semester duration " << endl;
		}
		else if (status == ENDD)
		{
			cout << "\nClass end date is over the semester duration " << endl;
		}
		else
		{
			cout << "\nBoth class start and end dates are over the semester duration" << endl;
		}
	}

	else
	{
		cout << "Maximum number of class exceeded! Please try again after deleting a course. " << endl;
	}
}

void CourseSchedule::removeCourse()
{
	int sel = maxSize + 1; //initialize so that it doesn't accidentally delete unintended course 
	int cnt = sel - 1; //index of the array 

	//prompt the user input 
	cout << "Enter the order number of the course that you would like to delete. " << endl;
	cin >> sel;

	if (numCourses > 0)
	{
		//check validation 
		while (sel >= maxSize || sel < 0)
		{
			cout << "Invalid input! Please enter the proper order number: " << endl;
			cin >> sel;
		}

		// call remove function in Course class
		Courses[cnt].remove(Courses);

		//move all the other elements one to left 
		for (int i = sel; i < maxSize; i++)
		{
			Courses[cnt].replace(Courses, sel);
		}
		cout << "\nThe class has successfully been removed from your schedule!" << endl;

		numCourses--;
	}
	else
	{
		cout << "The class schedule is empty. " << endl;
	}

}

ostream &operator<<(ostream & output, const CourseSchedule & sched)
{
	output << "CLASS SCHEDULE\n" << "-----------------------\n" << "Name: " << sched.sname
		<< endl << "Semester: " << sched.smester
		<< endl << "Number of Classes: " << sched.numCourses
		<< "-----------------------------------------\n";

	// course description imported from Course.cpp ostream operator
	for (int i = 0; i < sched.numCourses; i++)
	{
		output << sched.Courses[i] << endl;
	}
	return output;
}
