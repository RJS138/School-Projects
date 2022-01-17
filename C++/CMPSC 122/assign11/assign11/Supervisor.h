/*
 * File: supervisor.h
 * Supervisor class definition.
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
 File Name: supervisor.h
 Name: Robert Saunders Jr
 PSU User ID: rjs6748
 Course Title: CMPSC 122 Summer 2020
 Due Time: Sunday August 2, 2020 @ 23:59
 Time of Last Modification: Sunday AUgust 2, 2020 @ 18:52
 Description: To understand inheritance and the importance of using OOP.
 */
#ifndef SUPERVISOR_H
#define SUPERVISOR_H


#include "manager.h"

class Supervisor : public Manager
{
public:
	Supervisor(string theName,
		float thePayRate,
		string thedept);
	string getDept() const;
	void setDept(string newDept);
	float pay(float newPayRate) const;

protected:
	string dept;
};

Supervisor::Supervisor(string theName, float thePayRate, string thedept) : Manager(theName, thePayRate, true)
{
	dept = thedept;
}

string Supervisor::getDept() const
{
	return dept;
}

void Supervisor::setDept(string newDept)
{
	dept = newDept;
}

float Supervisor::pay(float newPayRate) const
{
	return payRate;
}

#endif
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