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
	cout << "\nDestructor for CourseSchedule has been called. " << endl;
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
		if (status == clear)
		{
			Courses[numCourses] = cou;
			numCourses++;
		}
		else if (status == startD)
		{
			cout << "\nClass start date is over the semester duration " << endl;
		}
		else if (status == endD)
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
		cout << "Maximum number of classes exceeded! Please try again after deleting a course. " << endl;
	}
}

void CourseSchedule::removeCourse()
{
	int sel = maxSize + 1; //initialize so that it doesn't accidentally delete unintended course 
	int cnt = sel - 1; //index of the array 

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
	Courses[cnt].remove(Courses);

	//move all the other elements one to left 
	for (int i = sel; i < maxSize; i++)
	{
		Courses[cnt].replace(Courses, sel);
	}

	numCourses--;
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
		output << sched.Courses[i]<< endl;
	}
	return output;
}
