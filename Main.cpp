/*
CS 137 - Midterm Project 2017
Team EECS
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "CourseSchedule.h"
using namespace std;

void FirstScene(Semester);

int main()
{
	string name;
	string semesterName;
	Date startDate;
	Date endDate;
	Time startTime;
	Time endTime;
	int maxNum;
	char sel;
	string courseNum;
	string courseName;
	string meetingDays;
	int numOfUnits;
	Semester sem;

	cout << "What's your name?" << endl;
	getline(cin, name);
	cout << "Please enter the semester info in \n Semester_name \n mm/dd/yyyy(start_date) \n mm/dd/yyyy(end_date) format." << endl;
	cin >> sem;
	cout << "Maximum number of classes?" << endl;
	cin >> maxNum;

	CourseSchedule schedule(name, sem, maxNum);
	do
	{
		FirstScene(sem);
		cin >> sel;

		if (sel == '1')
		{
			cin.ignore();//flush
			cout << "The course number?" << endl;
			getline(cin, courseNum);
			cout << "The course name?" << endl;												
			getline(cin, courseName);
			cout << "What days does the class meet?" << endl;
			getline(cin, meetingDays);
			cout << "How many units is the class?" << endl;
			cin >> numOfUnits;
			cout << "What time does your class start? - in hh:mm am/pm format" << endl;
			cin >> startTime;
			cin.ignore();
			cout << "Verify your class's starting time" << endl;
			cout << startTime << endl;
			cout << "What time does your class end? - in hh:mm am/pm format" << endl;
			cin >> endTime;
			cin.ignore();
			cout << "Verify your class's ending time" << endl;
			cout << endTime << endl;
			cout << "What date does your class start? - Please enter in mm/dd/yyyy format." << endl;
			cin >> startDate;
			cin.ignore();
			cout << "Verify your class's starting date" << endl;
			cout << startDate << endl;
			cout << "What date does your class end?  - Please enter in mm/dd/yyyy format." << endl;
			cin >> endDate;
			cin.ignore();
			cout << "Verify your class's end date" << endl;
			cout << endDate;

			Course cou(courseNum, courseName, meetingDays, numOfUnits, startDate, endDate, startTime, endTime);
			schedule.addCourse(cou, sem, startDate, endDate);
		}
		else if (sel == '2')
		{
			schedule.removeCourse();
		}
		else if (sel == '3')
		{
			cout << "Your class schedule:" << endl;
			cout << schedule << endl; 
		}
		else if (sel == 'q' || sel == 'Q')
		{
		}
		else
		{
			cout << "Invalid selection. Try again." << endl;
			FirstScene(sem);
			cin >> sel;
		}
	} while (sel != 'q' && sel != 'Q');

	system("PAUSE");
	return 0;
}

void FirstScene(Semester sem)
{
	cout << "\nCOURSE ENTRY MENU FOR : " << sem << endl; //operator allowed 
	cout << "----------------------------------------------------------------" << endl;
	cout << "1) Enter a new course" << endl;
	cout << "2) Remove a course" << endl;
	cout << "3) Print a Semester Schedule" << endl;
	cout << "Q) Quit the program" << endl;
}