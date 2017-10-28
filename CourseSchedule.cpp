#include "CourseSchedule.h"

CourseSchedule::CourseSchedule(string studentName, Semester semest, int num) : sname(studentName), smester(semest), maxSize(num)
{
	numCourses = 0;
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
	return numCourses;
}

void CourseSchedule::setStudentName(string sn)
{
	sname = sn;
}
