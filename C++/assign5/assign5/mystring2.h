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
Assisted By(Line Numbers): Some of the program was provided in the assignment details.
File Name: mystring2.cpp
Name: Robert Saunders Jr
PSU User ID: rjs6748
Course Title: CMPSC 122 Summer 2020
Due Time: Sunday June 21, 2020 @ 23:59
Time of Last Modification: Sunday June 21, 2020 @ 22:48
Description: This project allows the use of dynamically allocated string functions.
*/
/*
This code is currently incomplete and does not work as intended. I am struggling to find a solution that does not result in a heap overwrite error. I tried to follow the lectures and go where I
stand currently and using the discussion board i remembered to add null characters to the end of the loops. However I get errors when trying to read in the driver file str1 and i "solved" this by
making the str1 in the driver file str1(""). Even though that is not a true fix but a band aid I also am struggling to fix the heap overflow when the user inputs their test examples.
*/
#ifndef _MYSTRING2_H
#define _MYSTRING2_H
#pragma warning(disable : 4996)
#include<iostream>
#include <cstring>

using namespace std;
typedef char ElementType;


class String
{
public:
	String(int maxSize = 1024);
	String(const char s[]);
	String(const String& str);
	~String();
	String& operator=(const String& str);

	void append(const String& str);
	bool operator >(const String& str) const;
	bool operator <(const String& str) const;

	String operator +=(const String& str);

	void print(ostream& out) const;
	int length() const;

	char operator [](int i) const;

private:
	int mySize;
	int myCapactiy;
	ElementType* myArrayPtr;
};

ostream& operator<<(ostream& out, const String& r);
#endif