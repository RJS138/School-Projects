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
Assisted By(Line Numbers): Had guidance from the discussion board on adding '\0' to the end of my loops specifically line #64
File Name: mystring.cpp
Name: Robert Saunders Jr
PSU User ID: rjs6748
Course Title: CMPSC 122 Summer 2020
Due Time: Sunday May 31, 2020 @ 23:59
Time of Last Modification: Sunday May 31, 2020 @ 19:38
Description: This project defines user created functions to mimic those in the cstring library
*/
#include "mystring.h"
#include <cstring>
#include <iostream>
#include <cstring>

using namespace std;

/* Returns length of string s*/
int mystrlen(const char* s)
{
	int lengthCount = 0, i = 0;
	while (s[i] != '\0')
	{
		lengthCount++;
		i++;
	}
	return lengthCount;
}

/* Compares the values of s1 and s2 to verify if they are equal*/
int mystrcmp(const char* s1, const char* s2)
{
	int i = 0;
	int hold1 = 0, hold2 = 0;
	do 
	{
		hold1 += s1[i];
		hold2 += s2[i];
		i++;
	} while (s2[i] != '\0' && s1[i] != '\0');
	return hold1 - hold2;
}

/* Returns a copy of s2 into char* s1*/
char* mystrcpy(char* s1, const char* s2)
{
	int i = 0;
	do 
	{
		s1[i] = s2[i];
		i++;
	} while (i < mystrlen(s2));
	s1[i] = '\0';
	return s1;
}

/* Appends s2 to the end of s1 */
char* mystrcat(char* s1, const char* s2)
{
	int s1L = mystrlen(s1);
	int l = 1, i = 0;
	do 
	{
		s1[s1L] = s2[i];
		i++;
		s1L++;

	} while (i < mystrlen(s2));
	s1[s1L] = '\0';
	return s1;
}
/* Example Execution of Driver File
If no any error outputs, your program passes all the tests. The End.

C:\Users\rsaun\OneDrive\Penn State\Summer 2020\CMPSC 122\assign2\x64\Debug\assign2.exe (process 13172) exited with code 0.
Press any key to close this window . . .
*/

