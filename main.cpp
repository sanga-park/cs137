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
	int maxNum;
	char sel;
	int courseNum;
	string courseName;
	string meetingDays;
	int numOfUnits;

	cout << "What's your name?" << endl;
	cin >> name;
	cout << "What semester?" << endl;
	cin >> semesterName;
	cout << "Starting date?" << endl;
	cin >> startDate;
	cout << "Ending date?" << endl;
	cin >> endDate;
	cout << "Maximum number of classes?" << endl;
	cin >> maxNum;

	Semester sem(semesterName, startDate, endDate);
	CourseSchedule cou(name, semesterName, maxNum);  // still has a problem derieved from courseschedule cpp file.

	do
	{
		FirstScene(sem);
		cin >> sel;

		if (sel == '1')
		{
			cout << "The course number?" << endl;
			cin >> courseNum;
			cout << "The course name?" << endl;
			cin >> courseName;
			cout << "When does the class meet?" << endl;
			cin >> meetingDays;
			cout << "How many units is the class?" << endl;
			cin >> numOfUnits;

		}
		else if (sel == '2')
		{

		}
		else if (sel == '3')
		{

		}
		else if (sel == 'q' || sel == 'Q')
		{

		}
		else
		{
			cout << "Invalid selection. Try again." << endl;
			FirstScene();
			cin >> sel;
		}
	} while (sel != 'q' && sel != 'Q');

}

void FirstScene(Semester sem)
{
	cout << "COURSE ENTRY MENU FOR: " << setw(11) << sem.getSemesterName << " (" << sem.getStartDate << "-" << sem.getEndDate << ")" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "1) Enter a new course" << endl;
	cout << "2) Remove a course" << endl;
	cout << "3) Print a Semester Schedule" << endl;
	cout << "Q) Quit the program" << endl;
}

