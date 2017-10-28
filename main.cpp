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
	cout << "Starting date?" << endl;
	cin >> startDate;
	cout << "Ending date?" << endl;
	cin >> endDate;
	cout << "Maximum number of classes?" << endl;
	cin >> maxNum;

	Semester sem(semesterName, startDate, endDate);
	CourseSchedule cou(name, semesterName, maxNum); // still has a problem derieved from courseschedule cpp file.
	
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
			cout << "What days does the class meet?" << endl;
			cin >> meetingDays;
			cout << "How many units is the class?" << endl;
			cin >> numOfUnits;
			cout << "What time does your class start?" << endl;
			cin >> startTime;
			cout << "Verify your class's starting time" << endl;
			cout << startTime << endl;
			cout << "What time does your class end?" << endl;
			cin >> endTime;
			cout << "Verify your class's ending time" << endl;
			cout << endTime << endl;
			cout << "What date does your class start?" << endl;
			cin >> startDate;
			cout << "Verify your class's starting date" << endl;
			cout << startDate << endl;
			cout << "What date does your class end?" << endl;
			cin >> endDate;
			cout << "Verify your class's end date" << endl;
			cout << endDate << endl;

			Course cou(courseNum, courseName, meetingDays, numOfUnits, startDate, endDate, startTime, endTime);

			// it says to use a classschedule function. this should be done once we're done with classschedule in courseschedule class.
		}
		else if (sel == '2')
		{

		}
		else if (sel == '3')
		{
			cout << "Your class schedule:" << endl;
//			cout << cou << endl;  uncommend if cou works.
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
	cout << "COURSE ENTRY MENU FOR: " << setw(11) << sem.getSemesterName << " (" << sem.getStartDate << "-" << sem.getEndDate << ")" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "1) Enter a new course" << endl;
	cout << "2) Remove a course" << endl;
	cout << "3) Print a Semester Schedule" << endl;
	cout << "Q) Quit the program" << endl;
}
