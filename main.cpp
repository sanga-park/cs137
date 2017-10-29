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

	cout << "What's your name?" << endl;
	cin >> name;
	cout << "What semester?" << endl;
	cin >> semesterName;
	cin.ignore(); //have to put this after string
	cout << "Starting date?" << endl;
	cin >> startDate;
	cin.ignore();
	cout << "Ending date?" << endl;
	cin >> endDate;
	cin.ignore();
	cout << "Maximum number of classes?" << endl;
	cin >> maxNum;
	cin.ignore();

	Semester sem(semesterName, startDate, endDate);
	CourseSchedule schedule(name, sem, maxNum);

	do
	{
		FirstScene(sem);
		cin >> sel;

		if (sel == '1')
		{
			cout << "The course number?" << endl;
			cin >> courseNum;						// cin cannot include space tho... maybe we should change this into cget(,)
			cout << "The course name?" << endl;
			cin >> courseName;
			cin.ignore();
			cout << "What days does the class meet?" << endl;
			cin >> meetingDays;
			cin.ignore();
			cout << "How many units is the class?" << endl;
			cin >> numOfUnits;
			cin.ignore();
			cout << "What time does your class start?" << endl;
			cin >> startTime;
			cin.ignore();
			cout << "Verify your class's starting time" << endl;
			cout << startTime << endl;
			cout << "What time does your class end?" << endl;
			cin >> endTime;
			cin.ignore();
			cout << "Verify your class's ending time" << endl;
			cout << endTime << endl;
			cout << "What date does your class start?" << endl;
			cin >> startDate;
			cin.ignore();
			cout << "Verify your class's starting date" << endl;
			cout << startDate << endl;
			cout << "What date does your class end?" << endl;
			cin >> endDate;
			cin.ignore();
			cout << "Verify your class's end date" << endl;
			cout << endDate << endl;

			Course cou(courseNum, courseName, meetingDays, numOfUnits, startDate, endDate, startTime, endTime);
			schedule.addCourse(cou, sem, startDate, endDate);
		}
		else if (sel == '2')
		{

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

}

void FirstScene(Semester sem)
{
	cout << "COURSE ENTRY MENU FOR: " << sem << endl; //operator allowed 
	cout << "----------------------------------------------------------------" << endl;
	cout << "1) Enter a new course" << endl;
	cout << "2) Remove a course" << endl;
	cout << "3) Print a Semester Schedule" << endl;
	cout << "Q) Quit the program" << endl;
}