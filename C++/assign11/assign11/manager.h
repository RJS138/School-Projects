/*
 * File: manager.h
 * Manager class definition.
 */
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
 Assisted By(Line Numbers): Some of the code was supplied in the starter manager and employee files.
 File Name: manager.h
 Name: Robert Saunders Jr
 PSU User ID: rjs6748
 Course Title: CMPSC 122 Summer 2020
 Due Time: Sunday August 2, 2020 @ 23:59
 Time of Last Modification: Sunday AUgust 2, 2020 @ 18:52
 Description: To understand inheritance and the importance of using OOP.
 */

#ifndef _MANAGER_H
#define _MANAGER_H

#include "employee.h"

class Manager : public Employee {
public:
	Manager(string theName,
		float thePayRate,
		bool isSalaried);

	bool getSalaried() const;

	float pay(float hoursWorked) const;

	
	
	void setSalaried(bool updateSal);

protected:
	bool salaried;
};


//Manager method definitions.



Manager::Manager(string theName,
	float thePayRate,
	bool isSalaried)
	: Employee(theName, thePayRate)
{
	salaried = isSalaried;
}

bool Manager::getSalaried() const
{
	return salaried;
}

float Manager::pay(float hoursWorked) const
{
	if (salaried)
		return payRate;
	// else 
	return Employee::pay(hoursWorked);
}

void Manager::setSalaried(bool updateSal)
{
	salaried = updateSal;
}


#endif // not defined _MANAGER_H 

/* Example execution of Driver File
For Employee:
Name: John
Pay: 1000
Changing the Employee's name...
New Name: Doug

For Manager:
Name: Matthew
Salaried: 1
Pay: 1200
Changing the Manager's salaried status...
New Pay: 48000

For Supervisor:
Name: Denise
Pay: 780
Dept: Accounting
Changing the Supervisor's pay rate...
New Pay: 900

C:\Users\rsaun\OneDrive\Penn State\Summer 2020\CMPSC 122\assign11\Debug\assign11.exe (process 15732) exited with code 0.
Press any key to close this window . . .
*/