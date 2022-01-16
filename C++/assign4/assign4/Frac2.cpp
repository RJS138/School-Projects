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
File Name: Frac2.cpp
Name: Robert Saunders Jr
PSU User ID: rjs6748
Course Title: CMPSC 122 Summer 2020
Due Time: Sunday June 14, 2020 @ 23:59
Time of Last Modification: Sunday June 14, 2020 @ 21:39
Description: This project allows the use to add, subtract, multiply, and divide fractions by overloading operators.
*/

#include "Frac2.h"
//------------------------------ Fraction ------------------------------------
Fraction::Fraction(int n, int d)
{
	numerator = (d < 0 ? -n : n);
	denominator = (d < 0 ? -d : d);
	reduce();

}

//------------------------------ Addition ------------------------------------
Fraction Fraction::operator+(const Fraction& a)
{
	Fraction t;

	t.numerator = (a.numerator * denominator) + (a.denominator * numerator);
	t.denominator = a.denominator * denominator;
	t.reduce();

	return t;
}

//------------------------------ Subtraction ------------------------------------
Fraction Fraction::operator-(const Fraction& a)
{
	Fraction t;

	t.numerator = -((a.numerator * denominator) - ( a.denominator * numerator));
	t.denominator = a.denominator * denominator;
	t.reduce();

	return t;
}

//------------------------------ Multiplication ------------------------------------
Fraction Fraction::operator*(const Fraction& a)
{
	Fraction t;

	t.numerator = (a.numerator * numerator);
	t.denominator = (a.denominator * denominator);
	t.reduce();

	return t;
}

//------------------------------ Division ------------------------------------
Fraction Fraction::operator/(const Fraction& a)
{
	Fraction t;
	t.numerator = (numerator * a.denominator);
	t.denominator = (denominator * a.numerator);
	t.reduce();

	return t;
}

//------------------------------ Less Than ------------------------------------
bool Fraction::operator<(const Fraction& a)
{
	if ((numerator / denominator) < (a.numerator / a.denominator))
		return true;
	else
		return false;
}

//------------------------------ Greater Than ------------------------------------
bool Fraction::operator>(const Fraction& a)
{
	if ((numerator / denominator) > (a.numerator / a.denominator))
		return true;
	else
		return false;
}
//------------------------------ Print Fraction ------------------------------------
ostream & operator<<(ostream& out, const Fraction& f1)
{
	if (f1.denominator == 0)
	{
		return out << endl << "DIVIDE BY ZERO ERROR" << endl;
	}
	else
	{
		return out << f1.numerator << " / " << f1.denominator;
	}
}

//------------------------------ Print Fraction as Float ------------------------------------
// void Fraction::printFractionAsFloat()
// {
// 	if (denominator == 0)
// 	{
// 	cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
// 	}
// 	else
// 	{
// 		cout << float(numerator) / float(denominator);
// 	}
// }
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
7 / 3 + 1 / 3 = 8 / 3
7 / 3 - 1 / 3 = 2 / 1
7 / 3 * 1 / 3 = 7 / 9
7 / 3 / 1 / 3 = 7 / 1
7 / 3 is:
  > 1 / 3 according to the overloaded > operator
  >= 1 / 3 according to the overloaded < operator

C:\Users\rsaun\OneDrive\Penn State\Summer 2020\CMPSC 122\assign4\Debug\assign4.exe (process 17620) exited with code 0.
Press any key to close this window . . .

*/