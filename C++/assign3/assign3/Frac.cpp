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
File Name: Frac.cpp
Name: Robert Saunders Jr
PSU User ID: rjs6748
Course Title: CMPSC 122 Summer 2020
Due Time: Sunday June 7, 2020 @ 23:59
Time of Last Modification: Sunday June 7, 2020 @ 20:32
Description: This project allows the use to add, subtract, multiply, and divide fractions through a class.
*/

#include "Frac.h"
//------------------------------ Fraction ------------------------------------
Fraction::Fraction(int n, int d)
{
	numerator = (d < 0 ? -n : n);
	denominator = (d < 0 ? -d : d);
	reduce();

}

//------------------------------ Addition ------------------------------------
Fraction Fraction::add(const Fraction& a)
{
	Fraction t;

	t.numerator = (a.numerator * denominator) + (a.denominator * numerator);
	t.denominator = a.denominator * denominator;
	t.reduce();

	return t;
}

//------------------------------ Subtraction ------------------------------------
Fraction Fraction::subtract(const Fraction& a)
{
	Fraction t;

	t.numerator = -((a.numerator * denominator) - ( a.denominator * numerator));
	t.denominator = a.denominator * denominator;
	t.reduce();

	return t;
}

//------------------------------ Multiplication ------------------------------------
Fraction Fraction::multiply(const Fraction& a)
{
	Fraction t;

	t.numerator = (a.numerator * numerator);
	t.denominator = (a.denominator * denominator);
	t.reduce();

	return t;
}

//------------------------------ Division ------------------------------------
Fraction Fraction::divide(const Fraction& a)
{
	Fraction t;
	t.numerator = (numerator * a.denominator);
	t.denominator = (denominator * a.numerator);
	t.reduce();

	return t;
}

//------------------------------ Print Fraction ------------------------------------
void Fraction::printFraction()
{
	if (denominator == 0)
	{
		cout << endl << "DIVIDE BY ZERO ERROR" << endl;
	}
	else
	{
		cout << numerator << " / " << denominator;
	}

}

//------------------------------ Print Fraction as Float ------------------------------------
void Fraction::printFractionAsFloat()
{
	if (denominator == 0)
	{
	cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
	}
	else
	{
		cout << float(numerator) / float(denominator);
	}
}
//------------------------------ Reduce ------------------------------------
void Fraction::reduce()
{
	int n = numerator < 0 ? -numerator : numerator;
	int d = denominator;
	int largest = n > d ? n : d;

	int gcd = 0;

	for (int loop = largest; loop >= 2; loop --)
	{
		if (numerator % loop == 0 && denominator % loop == 0)
		{
			gcd = loop;
			break;
		}
	}
	if (gcd != 0)
	{
		numerator /= gcd;
		denominator /= gcd;
	}
}

/* Result of running driver Program
-3 / 8 + 3 / 4 = 3 / 8
3 / 8 = 0.375

-3 / 8 - 3 / 4 = -9 / 8
-9 / 8 = -1.125

-3 / 8 * 3 / 4 = -9 / 32
-9 / 32 = -0.28125

-3 / 8 / 3 / 4 = -1 / 2
-1 / 2 = -0.5

C:\Users\rsaun\OneDrive\Penn State\Summer 2020\CMPSC 122\assign3\Debug\assign3.exe (process 10580) exited with code 0.
Press any key to close this window . . .
*/