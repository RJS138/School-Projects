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
Assisted By(Line Numbers): Almost all of the code was supplied via separate .cpp files. I combined all the separate algorithms and made the driver file output one consistent example to test all three algorithms at once.
File Name: project9ModifiedDriver.cpp
Name: Robert Saunders Jr
PSU User ID: rjs6748
Course Title: CMPSC 122 Summer 2020
Due Time: Sunday July 19, 2020 @ 23:59
Time of Last Modification: Thursday July 19, 2020 @ 19:16
Description: The understand and test understanding of runtime time efficiency.
*/


/******************************************************************************
 CMPSC122 Su Assignment: Project Algorithm Analysis -- sample driver
 ******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "timer.h"
using namespace std;

int Max_Subsequence_Sum_BLUE(const int A[], const int N) //Algorithm 1
{
	int This_Sum = 0, Max_Sum = 0;

	for (int i = 0; i < N; i++)
	{
		This_Sum = 0;
		for (int j = i; j < N; j++)
		{
			This_Sum += A[j];
			if (This_Sum > Max_Sum)
			{
				Max_Sum = This_Sum;
			}
		}
	}
	return Max_Sum;
}

int Max_Subsequence_Sum_GREEN(const int A[], const int N) //Algorithm 2
{
	int This_Sum = 0, Max_Sum = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			This_Sum = 0;
			for (int k = i; k <= j; k++)
			{
				This_Sum += A[k];
			}
			if (This_Sum > Max_Sum)
			{
				Max_Sum = This_Sum;
			}
		}
	}
	return Max_Sum;
}

int Max_Subsequence_Sum_RED(const int A[], const int N) //Algorithm 3
{
	int This_Sum = 0, Max_Sum = 0;

	for (int Seq_End = 0; Seq_End < N; Seq_End++)
	{
		This_Sum += A[Seq_End];

		if (This_Sum > Max_Sum)
		{
			Max_Sum = This_Sum;
		}
		else if (This_Sum < 0)
		{
			This_Sum = 0;
		}
	}
	return Max_Sum;
}


int main( )
{
	int Size = 64;
	int *Vec, Result_BLUE[6], Result_GREEN[6], Result_RED[6];
	char Answer;
	Timer T_BLUE[6], T_GREEN[6], T_RED[6];
	
	for ( int i = 0; i < 6; i++)
	{ 
		Vec = new int [Size];
		srand( time(0) );
		
		for (int I=0; I<Size; I++)
		{
			Vec[I] = rand() % 100 - 50;
		}
		
		cout << "Do you wish to view the array contents? (Y or N): ";
		cin >> Answer;
		
		if (Answer == 'Y' || Answer == 'y')
		{
			for (int J=0; J<Size; J++)
			{
				cout << Vec[J] << "\n";
			}
		}
		cout << endl;
		
		T_BLUE[i].start();
		Result_BLUE[i]  = Max_Subsequence_Sum_BLUE( Vec, Size );
		T_BLUE[i].stop();

		T_GREEN[i].start();
		Result_GREEN[i] = Max_Subsequence_Sum_GREEN(Vec, Size);
		T_GREEN[i].stop();

		T_RED[i].start();
		Result_RED[i] = Max_Subsequence_Sum_RED(Vec, Size);
		T_RED[i].stop();
		
		Size = 2* Size;
		
	}
	
	for ( int i = 0; i < 6; i++)
	{ 
		cout << "Maximum contiguous subsequence sum (BLUE): " << Result_BLUE [i] << "\n";
		T_BLUE[i].show();
		cout << endl;

		cout << "Maximum contiguous subsequence sum (GREEN): " << Result_GREEN[i] << "\n";
		T_GREEN[i].show();
		cout << endl;

		cout << "Maximum contiguous subsequence sum (RED): " << Result_RED[i] << "\n";
		T_RED[i].show();
		cout << endl;
	}
}

