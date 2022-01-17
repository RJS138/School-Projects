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
//with C++, 2nd ed., Prentice-Hall, 2005.

/*-- BigInt.cpp-------------------------------------------------------------
                This file implements BigInt member functions.
--------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>
using namespace std;

#include "BigInt.h"

//--- Definition of read()
void BigInt::read(istream & in)
{
  static bool instruct = true;
  if (instruct)
  {
     cout << "Enter " << DIGITS_PER_BLOCK << "-digit blocks, separated by "
            "spaces.\nEnter a negative integer in last block to signal "
            "the end of input.\n\n";
    instruct = false;
  }
  short int block;
  const short int MAX_BLOCK = (short) pow(10.0, DIGITS_PER_BLOCK) - 1;
  for (;;)
  {
    in >> block;
    if (block < 0) return;

    if (block > MAX_BLOCK)
      cerr << "Illegal block -- " << block << " -- ignoring\n";
    else
      myList.push_back(block);
  }
}

//--- Definition of display()
void BigInt::display(ostream & out) const
{
   int blockCount = 0;
   const int BLOCKS_PER_LINE = 20;   // number of blocks to display per line

   // Please note that I use the new C++ standard of auto type instead of interator in the for loop.
   //for (list<short int>::const_iterator it = myList.begin(); ; )  // this is the old version
   for (auto it = myList.begin(); ; ) // this is the new version
   {
      out << setfill('0');
      if (blockCount == 0)
         out << setfill(' ');
 
      if (it == myList.end())
         return;

      out << setw(3) << *it;
      blockCount++ ;

      it++;
      if (it != myList.end())
      {
         out << ',';
         if (blockCount > 0 && blockCount % BLOCKS_PER_LINE == 0)
            out << endl;
      }
   }
}

//--- Definition of operator+()
BigInt BigInt::operator+(BigInt addend2)
{
   BigInt sum;
   short int first,                  // a block of 1st addend (this object)
             second,                 // a block of 2nd addend (addend2)
             result,                 // a block in their sum
             carry = 0;              // the carry in adding two blocks

 // Please note that I use the new C++ standard of auto type instead of reverse_interator in the for loop.
 /* this block is the old version
   list<short int>::reverse_iterator // to iterate right to left
      it1 = myList.rbegin(),         //   through 1st list, and
      it2 = addend2.myList.rbegin(); //   through 2nd list
*/
    
// this is the new version
 auto      it1 = myList.rbegin(),         //   through 1st list, and
           it2 = addend2.myList.rbegin(); //   through 2nd list

   while (it1 != myList.rend() || it2 != addend2.myList.rend())
   {
      if (it1 != myList.rend())
      {
         first = *it1;
         it1++ ;
      }
      else
         first = 0;
      if (it2 != addend2.myList.rend())
      {
         second = *it2;
         it2++ ;
      }
      else
         second = 0;

      short int temp = first + second + carry;
      result = temp % 1000;
      carry = temp / 1000;
      sum.myList.push_front(result);
   }

   if (carry > 0)
      sum.myList.push_front(carry);

   return sum;
}

//--- Definition of operator-()
BigInt BigInt::operator-(BigInt addend2)
{
    BigInt endresult;
    short int first,
        second,
        result,
        carry = 0;

    auto it1 = myList.rbegin(),
        it2 = addend2.myList.rbegin();
    if (addend2.myList.size() > myList.size())
    {
        return 0;
    }
    while (it1 != myList.rend() || it2 != addend2.myList.rend())
    {
		if (it1 != myList.rend())
		{
			first = *it1;
			it1++;
		}
		else
			first = 0;
		if (it2 != addend2.myList.rend())
		{
			second = *it2;
			it2++;
		}
		else
			second = 0;

		short int temp = first - second - carry;
        if (temp < 0)
        {
            temp += 1000;
            result = temp;
            carry = 1;
        }
        else
        {
			result = temp % 1000;
            carry = 0;
        }
		endresult.myList.push_front(result);
    }
	return endresult;
}

//--- Definition of operator>()
bool BigInt::operator>(BigInt addend2)
{
    BigInt endresult1, endresult2;
	short int first,
		second,
		result = 0,
        temp = 0,
		carry = 0;

	auto it1 = myList.rbegin(),
		it2 = addend2.myList.rbegin();
    while (it1 != myList.rend() || it2 != addend2.myList.rend())
    {
		if (it1 != myList.rend())
		{
			first = *it1;
			it1++;
		}
		else
			first = 0;
		if (it2 != addend2.myList.rend())
		{
			second = *it2;
			it2++;
		}
		else
			second = 0;

        if (first > second)
        {
           temp = 1;
        }
        else
        {
           temp = -1;
        }
        result += temp;
        endresult1.myList.push_back(first);
        endresult2.myList.push_back(second);
    }
	if (result >= 0)
	{
		return true;
	}
    else
    {
        return false;
    }
}

// Start of my BIGINT * operator. Is unfinished i had trouble finding a simple method for this one.
//--- Definition of operator*()
// BigInt BigInt::operator*(BigInt addend2)
// {
// 	BigInt endresult;
// 	short int first,
// 		second,
// 		result = 0,
// 		carry = 0;
//     int i = 0;
// 
// 	auto it1 = myList.rbegin(),
// 		it2 = addend2.myList.rbegin();
//     while (it1 != myList.rend() || it2 != addend2.myList.rend())
//     {
// 		if (it1 != myList.rend())
// 		{
// 			first = *it1;
// 			it1++;
// 		}
// 		else
// 			first = 0;
// 		if (it2 != addend2.myList.rend())
// 		{
// 			second = *it2;
// 			it2++;
// 		}
// 		else
// 			second = 0;
// 
//         short int temp = first * second + carry;
// 		result = temp % 1000;
// 		carry = temp / 1000;
// 		endresult.myList.push_front(result);
//         i++;
//     }
// 	
//     return endresult;
// }

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