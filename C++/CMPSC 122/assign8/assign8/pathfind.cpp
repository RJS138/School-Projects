/*Academic Integrity Statement:
*I certify that, while others may have assisted me in brainstorming,             *
*debugging, and validating this program, the program                             *
*itself is my own work. I understand that submitting                             *
*code which is the work of other individuals is a                                *
*violation of the course Academic Integrity Policy                               *
*and may result in a zero credit for the assignment,                             *
*or course failure and a report to the Academic Dishonesty Board.                *
*I also understand that if I knowingly give my original work to                  *
*another individual that it could also result in a zero credit for               *
*the assignment, or course failure and a report to the Academic Dishonesty Board.*/
/*
Assisted By(Line Numbers): 
File Name: proj6.cpp
Name: Robert Saunders Jr
PSU User ID: rjs6748
Course Title: CMPSC 122 Summer 2020
Due Time: Sunday July 12, 2020 @ 23:59
Time of Last Modification: Thursday July 9, 2020 @ 15:47
Description: To get practice in designing recursive functions and to gain experience in algorithm time efficiency. 
*/

#include <iostream>
#include <string>
using namespace std;

#include "timer_1.h"

int pathcount(int m, int n);

int main()
{
	Timer t;
	int north, east, totalpaths;
	char response;
	do
	{
		cout << " How many points north of A is B? ";
		cin >> north;
		cout << "\n How many points east of A is B? ";
		cin >> east;
		t.start();
		totalpaths = pathcount(north, east);
		t.stop();
		cout << "There are " << totalpaths << " northeast paths between A and B." << endl;
		t.show();
		cout << "Enter y or Y to continue to the next example or any other letter to exit: ";
		cin >> response;
	} while (response == 'Y' || response == 'y');
	return 0;
}

int pathcount(int m, int n)
{
	//Base case for end being the start
	if (m == 0 && n == 0)
	{
		return 0;
	}
	//Base case for straight line paths. Only 2 possible outcomes.
	else if (m == 0 || n == 0)
	{
		return 1;
	}
	//Recursive case where path counts will equal all possible combinations of north and east.
	else
	{
		return pathcount(m - 1, n) + pathcount(m, n - 1);
	}
}
/* Example Execution
 How many points north of A is B? 4

 How many points east of A is B? 8
There are 495 northeast paths between A and B.
  Process Timer
  -------------------------------
  Elapsed Time   : 0.001s
Enter y or Y to continue to the next example or any other letter to exit: y
 How many points north of A is B? 16

 How many points east of A is B? 16
There are 601080390 northeast paths between A and B.
  Process Timer
  -------------------------------
  Elapsed Time   : 16.611s
Enter y or Y to continue to the next example or any other letter to exit: b

C:\Users\rsaun\OneDrive\Penn State\Summer 2020\CMPSC 122\assign8\Debug\assign8.exe (process 16140) exited with code 0.
Press any key to close this window . . .

*/