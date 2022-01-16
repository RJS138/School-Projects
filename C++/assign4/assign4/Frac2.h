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
File Name: Frac2.h
Name: Robert Saunders Jr
PSU User ID: rjs6748
Course Title: CMPSC 122 Summer 2020
Due Time: Sunday June 14, 2020 @ 23:59
Time of Last Modification: Sunday June 14, 2020 @ 21:39
Description: This project allows the use to add, subtract, multiply, and divide fractions by overloading operators.
*/

#ifndef FRAC2_H
#define FRAC2_H
#include <iostream>
using namespace std;

class Fraction
{
public:
	Fraction(int = 0, int = 1);
	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);
	bool operator<(const Fraction&);
	bool operator>(const Fraction&);
	friend ostream& operator<<(ostream& out, const Fraction& f1);

private:
	int numerator;
	int denominator;

	void reduce();
};
#endif

ostream& operator<<(ostream& out, const Fraction& f1);