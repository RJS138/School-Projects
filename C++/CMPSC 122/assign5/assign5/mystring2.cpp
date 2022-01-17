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
#include "mystring2.h"

String::String(int maxSize)
{
	mySize = 0;
	myCapactiy = 0;
	myArrayPtr = new ElementType[maxSize];
}

String::String(const char s[])
{
	mySize = strlen(s);
	myCapactiy = strlen(s);
	myArrayPtr = new ElementType[myCapactiy];
	for (int i = 0; i < mySize; i++)
	{
		myArrayPtr[i] = s[i];
	}
	myArrayPtr[myCapactiy] = NULL;
}

String::String(const String& str)
{
	mySize = str.mySize;
	myCapactiy = str.myCapactiy;
	myArrayPtr = new ElementType[myCapactiy];

	for (int i = 0; i < mySize; i++)
	{
		myArrayPtr[i] = str.myArrayPtr[i];
	}
	myArrayPtr[myCapactiy] = NULL;
}

String::~String()
{
	delete[] myArrayPtr;
}


String& String::operator=(const String& str)
{
	if (this != &str)
	{
		mySize = str.mySize;
		myCapactiy = str.myCapactiy;
		delete[] myArrayPtr;
		myArrayPtr = new ElementType[myCapactiy];
		for (int i = 0; i < myCapactiy; i++)
		{
			myArrayPtr[i] = str.myArrayPtr[i];
		}
		myArrayPtr[myCapactiy] = NULL;
	}
	return *this;
}

void String::append(const String& str) 
{ 
	strcat(myArrayPtr, str.myArrayPtr);  
	mySize += str.mySize; 
	delete[] str.myArrayPtr;
	myArrayPtr[mySize] = NULL;
}

bool String::operator >(const String& str) const 
{ 
	return strcmp(myArrayPtr, str.myArrayPtr) > 0; 
}

bool String::operator <(const String& str) const 
{ 
	return strcmp(myArrayPtr, str.myArrayPtr) < 0; 
}

String String::operator +=(const String& str) 
{ 
	append(str); 
	return *this; 
}

void String::print(ostream& out) const 
{ 
	out << myArrayPtr; 
}

int String::length() const 
{ 
	return mySize; 
}

char String::operator [](int i) const
{
	if (i < 0 || i >= mySize) 
	{
		cerr << "can't access location " << i << " of string \"" << myArrayPtr << "\"" << endl;    
		return '\0';
	} 
	return myArrayPtr[i];
}

ostream& operator<<(ostream& out, const String& s)
{ 
	s.print(out);
	return out;
}
/* Example Execution of Driver File

*No current full execution i keep getting errors.

*/