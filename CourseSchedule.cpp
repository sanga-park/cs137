#include "CourseSchedule.h"

CourseSchedule::CourseSchedule(string studentName, Semester semest, int num) : sname(studentName), smester(semest), maxSize(num)
{
	CourseSchedule::numCourses = 0;
	Courses = new Course[maxSize];
}

CourseSchedule::~CourseSchedule()
{
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
	//  x      o  --1 -->startD
	//  o      x  --4 -->endD
	//  x      x  --2 -->both
	sCnt = ((sem.getSemStartDate < sDate) ? 4 : 2);
	eCnt = ((sem.getSemEndDate > eDate) ? 1 : 0);
	
	return sCnt + eCnt;
}

void CourseSchedule::addCourse(Course& cs, Semester sem, Date sDate, Date eDate)
{
	//allow adding a course only when the dates are within the semester duration
	if (checkDates(sem, sDate, eDate)  == clear)
	{
		Courses[numCourses] = cs;
		numCourses++;
	}
}

ostream &operator<<(ostream & output, const CourseSchedule & sched)
{
	output << "CLASS SCHEDULE\n" << "-----------------------\n" << "Name: " << sched.sname
		<< endl << "Semester: " << sched.smester
		<< endl << "Number of Classes: " << sched.CourseSchedule::numCourses
		<< "-----------------------------------------\n";
		
		// course description imported from course.cpp ostream operator
	for (int i = 0; i < sched.CourseSchedule::numCourses; i++)
	{
		output << sched.Courses[i] << endl << endl;
	}
	return output;
}
