#include "CourseSchedule.h"

CourseSchedule::CourseSchedule(string studentName, Semester semest, int num) : sname(studentName), smester(semest), maxSize(num)
{
	CourseSchedule::numCourses = 0;
	Courses = new Course[maxSize]; 
	//a pointer to Course that has array elements 

	//if it doesn't work considering using for loop and initialize individual elements 
	for (int i = 0; i < maxSize; i++)
	{
		Courses[i] = nullptr;
	}
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
	sCnt = ((sem.getSemStartDate < sDate) ? 4 : 2);
	eCnt = ((sem.getSemEndDate > eDate) ? 1 : 0);

	return sCnt + eCnt;
}

void CourseSchedule::addCourse(Course& cs, Semester sem, Date sDate, Date eDate)
{
	//prompt the user input 
	int sel=maxSize+1; //initialize so that it doesn't accidentally delete unintended course 
	cout << "Enter the order of the course that you would like to delete. " << endl; //It's kinda crude but it's a simplest way that I can think of.
	cin >> sel;
	//check validation 
	while (sel >= maxSize || sel < 0)
	{
		cout << "Invalid input! Please enter the proper order: " << endl;
		cin >> sel;
	}

	//allow adding a course only when the dates are within the semester duration
	if (checkDates(sem, sDate, eDate) == 5)
	{
		cs[sel]
	}
}

void CourseSchedule::removeCourse()
{
	int sel = maxSize + 1; //initialize so that it doesn't accidentally delete unintended course 
	int cnt = sel - 1;

	//prompt the user input 
	cout << "Enter the order of the course that you would like to delete. " << endl; //It's kinda crude but it's a simplest way that I can think of.
	cin >> sel;
	//check validation 
	while (sel >= maxSize || sel < 0)
	{
		cout << "Invalid input! Please enter the proper order: " << endl;
		cin >> sel;
	}

	/*
		string courseNum;
		string courseName;
		string meetDays;
		double unit;
		Date startDate;
		Date endDate;
		Time startTime;
		Time endTime;
		*/
	//remove information of selected element in the array  

	Courses[cnt].getCourseName() = nullptr;


	//move all the other information of elements one to left 
	for (int i = sel; i < maxSize; i++)
	{
		Courses[i - 1].courseName = Courses[i].courseName; //can't use memberwise function ... 
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