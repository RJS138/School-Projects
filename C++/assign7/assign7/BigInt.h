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
Assisted By(Line Numbers): Some of the code was provided from the provided documents. My code is in the - > operations specifically. I did not get the * operator to function.
File Name: proj6.cpp
Name: Robert Saunders Jr
PSU User ID: rjs6748
Course Title: CMPSC 122 Summer 2020
Due Time: Sunday July 5, 2020 @ 23:59
Time of Last Modification: Sunday July 5, 2020 @ 21:47
Description: This project is a template for big Ints and their processing.
*/
//cmpsc122 Su Assignment 7 revised on June 30, 2020
//Modified from textbook Larry Nyhoff,  ADTs, Data Structures, and Problem Solving 
//with C++, 2nd ed., Prentice-Hall

/*-- BigInt.h -------------------------------------------------------------
 
  This header file defines the data type BigInt for processing 
  integers of any size.
  Basic operations are:
     Constructor
     +:         Addition operator
     read():    Read a BigInt object
     display(): Display a BigInt object
     <<, >> :   Input and output operators
-------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>       // setfill(), setw()
#include <list>
#include <cmath>	// pow
using namespace std;

#ifndef BIGINT
#define BIGINT

const int DIGITS_PER_BLOCK = 3;

const int MODULUS = (short int)pow(10.0, DIGITS_PER_BLOCK);

class BigInt
{
 public:
	/***** Constructors *****/
	BigInt()
	{ }
	/*-----------------------------------------------------------------------
	Default cConstructor
	Precondition: None
	Postcondition: list<short int>'s constructor was used to build
	this BigInt object.
	-----------------------------------------------------------------------*/
	BigInt(int n);
	/*-----------------------------------------------------------------------
	Construct BigInt equivalent of n.
	Precondition: n >= 0.
	Postcondition: This BigInt is the equivalent of integer n.
	-----------------------------------------------------------------------*/
	/******** Function Members ********/
	/***** Constructor *****/
	// Let the list<short int> constructor take care of this.

	/***** read *****/
	void read(istream & in);
	/*-----------------------------------------------------------------------
		Read a BigInt.

		Precondition:  istream in is open and contains blocks of nonnegative
			integers having at most DIGITS_PER_BLOCK digits per block.
		Postcondition: Blocks have been removed from in and added to myList.
	-----------------------------------------------------------------------*/

	/***** display *****/
	void display(ostream & out) const;
	/*-----------------------------------------------------------------------
		Display a BigInt.

		Precondition:  ostream out is open.
		Postcondition: The large integer represented by this BigInt object
			has been formatted with the usual comma separators and inserted
			into ostream out. 
	------------------------------------------------------------------------*/

	/***** addition operator *****/
	BigInt operator+(BigInt addend2);
	/*------------------------------------------------------------------------
		Add two BigInts.

		Precondition:  addend2 is the second addend.
		Postcondition: The BigInt representing the sum of the large integer
		represented by this BigInt object and addend2 is returned.
	------------------------------------------------------------------------*/

	/***** subtraction operator *****/
	BigInt operator-(BigInt addend2);

	/***** comparison operator *****/
	bool operator>(BigInt addend2);

	/***** multiplication operator *****/
	BigInt operator*(BigInt addend2);

	private:
	/*** Data Members ***/
	list<short int> myList;
};  // end of BigInt class declaration

//-- Definition of constructor
inline BigInt::BigInt(int n)
{
	do
	{
		myList.push_front(n % MODULUS);
		n /= MODULUS;
	}
	while (n > 0);
}
//------ Input and output operators
inline istream & operator>>(istream & in, BigInt & number)
{
  number.read(in);
  return in;
}

inline ostream & operator<<(ostream & out, const BigInt & number)
{
  number.display(out);
  return out;
}

#endif

/* Example Execution
Enter a big integer:
Enter 3-digit blocks, separated by spaces.
Enter a negative integer in last block to signal the end of input.

454 456 456 -1
Enter another big integer:
123 123 123 -1
The sum of
		454,456,456 + 123,123,123
is
		577,579,579

The bigger number of
		454,456,456
and
		123,123,123
is
		454,456,456

The subtraction of
		454,456,456 - 123,123,123
is
		331,333,333

Add more integers (Y or N)? n

C:\Users\rsaun\OneDrive\Penn State\Summer 2020\CMPSC 122\assign7\Debug\assign7.exe (process 12004) exited with code 0.
Press any key to close this window . . .

*/