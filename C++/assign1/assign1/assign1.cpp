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
Assisted By(Line Numbers): N/A
File Name: assign1.cpp
Name: Robert Saunders Jr
PSU User ID: rjs6748
Course Title: CMPSC 122 Summer 2020
Due Time: Sunday May 24, 2020 @ 23:59
Time of Last Modification: Thursday May 21, 2020 @ 13:05
Description: THis project is a guessing game designed to practice concepts previously learned in C++
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playerController();
void computerController();
bool playAgain(char & userResponse);
bool isResponseValid(char c);

int main()
{
	//seeds rand function
	srand(unsigned(time(NULL)));
	char userResponse;
	bool again, responseValid;

	//loop for validating user input
	do 
	{
		cout << "Would you like to (p)lay or watch the (c)omputer play?" << endl;
		cin >> userResponse;
		responseValid = isResponseValid(userResponse);
	} while (!responseValid);

	//main game loop
	do 
	{
		if (toupper(userResponse) == 'P')
		{
			playerController();
		}
		else
		{
			computerController();
		}
		again = playAgain(userResponse);
	} while (again == true);
	return 0;
}

//player function assumes player is going to guess according to program response
void playerController()
{
	int userNum, randNum;
	randNum = rand() % 100;
	do 
	{
		cout << "Enter your guess between 1 and 100" << endl;
		cin >> userNum;
		if (userNum > randNum)
		{
			cout << "Sorry your guess is too high try again" << endl;
		} 
		else if (userNum < randNum)
		{
			cout << "Sorry your guess is too low try again" << endl;
		}
	} while (userNum != randNum);
	cout << "Congrats, you guessed the correct number, " << randNum << endl;
}

//computer function with guessing logic to make slightly smarter AI, could be even faster but i wanted to keep AI human like
void computerController()
{
	int compNum, randNum;
	int high = 100, low = 0;
	randNum = rand() % 100;
	do
	{
		//rand becomes restricted based off previous guesses
		compNum = rand() % (high - low + 1) + low;
		cout << "The computers guess is " << compNum << endl;
	
		if (compNum > randNum)
		{
			cout << "Sorry your guess is too high try again" << endl;
			high = compNum - 1;
		}
		else if (compNum < randNum)
		{
			cout << "Sorry your guess is too low try again" << endl;
			low = compNum + 1;
		}
	} while (compNum != randNum);
	cout << "Congrats, you guessed the correct number, " << randNum << endl;
}

//function for repeat play validation
bool playAgain(char & userResponse)
{
	cout << "Would you like to (p)lay, watch the (c)omputer play or (q)uit?" << endl;
	cin >> userResponse;
	return isResponseValid(userResponse);
}

//function for validating user response
bool isResponseValid(char c)
{
	switch (toupper(c))
	{
		case 'P':
			return true;
		case 'C':
			return true;
		default:
			return false;
	}
}
/* Example Execution
Would you like to (p)lay or watch the (c)omputer play?
p
Enter your guess between 1 and 100
50
Sorry your guess is too low try again
Enter your guess between 1 and 100
70
Sorry your guess is too low try again
Enter your guess between 1 and 100
80
Sorry your guess is too low try again
Enter your guess between 1 and 100
90
Sorry your guess is too low try again
Enter your guess between 1 and 100
99
Sorry your guess is too high try again
Enter your guess between 1 and 100
98
Sorry your guess is too high try again
Enter your guess between 1 and 100
95
Sorry your guess is too high try again
Enter your guess between 1 and 100
92
Sorry your guess is too low try again
Enter your guess between 1 and 100
93
Sorry your guess is too low try again
Enter your guess between 1 and 100
94
Congrats, you guessed the correct number, 94
Would you like to (p)lay, watch the (c)omputer play or (q)uit?
c
The computers guess is 75
Sorry your guess is too high try again
The computers guess is 36
Sorry your guess is too low try again
The computers guess is 68
Sorry your guess is too high try again
The computers guess is 49
Sorry your guess is too high try again
The computers guess is 44
Sorry your guess is too low try again
The computers guess is 48
Congrats, you guessed the correct number, 48
Would you like to (p)lay, watch the (c)omputer play or (q)uit?
q

C:\Users\rsaun\OneDrive\Penn State\Summer 2020\CMPSC 122\assign1\Debug\assign1.exe (process 9436) exited with code 0.
Press any key to close this window . . .
*/