#include "CourseSchedule.h"

int CourseSchedule::numCourses;

CourseSchedule::CourseSchedule(string studentName, Semester semest, int num) : sname(studentName), smester(semest), maxSize(num)
{
	CourseSchedule::numCourses = 0;
	Courses = new Course[maxSize]; 
}

CourseSchedule::~CourseSchedule()
{
	//numCourses = 0;
	//maxSize = 0;
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
	return CourseSchedule::numCourses;
}

void CourseSchedule::setStudentName(string sn)
{
	sname = sn;
}


// utility function 
int CourseSchedule::checkDates(Semester sem, Date sDate, Date eDate)
{
	// count if start or end date satisfies the semester duration 
	int sCnt = 0;
	int eCnt = 0;

	// start  end       o:within 
	//  o      o  --5 -->clear
	//  x      o  --3 -->startD
	//  o      x  --4 -->endD
	//  x      x  --2 -->both
	sCnt = ((sem.getSemStartDate() < sDate) ? 4 : 2);
	eCnt = ((sem.getSemEndDate() > eDate) ? 1 : 0);

	return sCnt + eCnt;
}

void CourseSchedule::addCourse(Course& cou, Semester sem, Date sDate, Date eDate)
{
	//allow adding a course only when the dates are within the semester duration
	if (checkDates(sem, sDate, eDate) == 5)
	{
		cou = Courses[CourseSchedule::numCourses];
		CourseSchedule::numCourses++;
	}
}

void CourseSchedule::removeCourse(Course* cs)
{
	int sel = maxSize + 1; //initialize so that it doesn't accidentally delete unintended course 
	int cnt = sel - 1; //same as maxSize

	//prompt the user input 
	cout << "Enter the order number of the course that you would like to delete. " << endl;
	cin >> sel;
	//check validation 
	while (sel >= maxSize || sel < 0)
	{
		cout << "Invalid input! Please enter the proper order number: " << endl;
		cin >> sel;
	}

	// call remove function in Course class
	// I don't know if it will delete only one element or not -- we need to check 
	cs[sel].remove(cs);

	//count 
	CourseSchedule::numCourses--;

	//move all the other information of elements one to left 
	for (int i = sel; i < maxSize; i++)
	{
		cs[sel].replace(cs, sel);
	}

	// we should search how to remove the element of the arry that is already declared.
}

ostream &operator<<(ostream & output, const CourseSchedule & sched)
{
	output << "CLASS SCHEDULE\n" << "-----------------------\n" << "Name: " << sched.sname
		<< endl << "Semester: " << sched.smester
		<< endl << "Number of Classes: " << sched.numCourses
		<< "-----------------------------------------\n";

	// course description imported from course.cpp ostream operator
	for (int i = 0; i < sched.numCourses; i++)
	{
		output << sched.Courses[i] << "\n" << endl;
	}
	return output;
}
