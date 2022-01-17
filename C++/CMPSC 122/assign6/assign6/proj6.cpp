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
Assisted By(Line Numbers): 
File Name: proj6.cpp
Name: Robert Saunders Jr
PSU User ID: rjs6748
Course Title: CMPSC 122 Summer 2020
Due Time: Sunday June 28, 2020 @ 23:59
Time of Last Modification: Wednesday June 24, 2020 @ 12:58
Description: This project allows the user to visualize and evaluate Postfix(RPN) expressions.
*/
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	stack<int> mystack;
	string rpnIn;
	int temp1 = 0, temp2 = 0, temp3 = 0;
	string response = "N";

	do
	{
		mystack.empty();
		rpnIn.clear();
		cout << "Please Enter the RPN expression to be evaluated:"
			<< "\n(NOTE: Each digit or operator should be separated by a space and end with :)" << endl;
		getline(cin, rpnIn);
		
		//main loop
		for (int i = 0; i < rpnIn.length(); i++)
		{
			//pushes values onto stack as number not character
			if (isdigit(rpnIn[i]))
			{
				cout << "Token = " << rpnIn[i] << " Push " << rpnIn[i] << endl;
				int pushVal = rpnIn[i];
				mystack.push(pushVal - '0');
			}
			else
			{
				//logic for operator decisions
				switch (rpnIn[i])
				{
				case '+':
					cout << "Token = " << rpnIn[i] << " Pop " << mystack.top();
					temp1 = mystack.top();
					mystack.pop();
					cout << " Pop " << mystack.top();
					temp2 = mystack.top();
					mystack.pop();
					temp3 = temp1 + temp2;
					mystack.push(temp3);
					cout << " Push " << temp3 << endl;
					break;
				case '-':
					cout << "Token = " << rpnIn[i] << " Pop " << mystack.top();
					temp1 = mystack.top();
					mystack.pop();
					cout << " Pop " << mystack.top();
					temp2 = mystack.top();
					mystack.pop();
					temp3 = temp2 - temp1;
					mystack.push(temp3);
					cout << " Push " << temp3 << endl;
					break;
				case '*':
					cout << "Token = " << rpnIn[i] << " Pop " << mystack.top();
					temp1 = mystack.top();
					mystack.pop();
					cout << " Pop " << mystack.top();
					temp2 = mystack.top();
					mystack.pop();
					temp3 = temp1 * temp2;
					mystack.push(temp3);
					cout << " Push " << temp3 << endl;
					break;
				case '/':
					cout << "Token = " << rpnIn[i] << " Pop " << mystack.top();
					temp1 = mystack.top();
					mystack.pop();
					cout << " Pop " << mystack.top();
					temp2 = mystack.top();
					mystack.pop();
					temp3 = temp2 / temp1;
					mystack.push(temp3);
					cout << " Push " << temp3 << endl;
					break;
				case ':':
					cout << "Token = Pop " << mystack.top();
					mystack.pop();
					break;

				//sanity for spaces and invalid symbols 
				case ' ':
					break;
				default:
					cout << "ERROR: Incorrect symbol Entered: " << rpnIn[i] << endl;
					break;
				}
			}
		}

		cout << "\nType 'Y' or 'y' to continue, or type any other letter to quit: ";
		getline(cin, response);
	} while (response == "Y" || response == "y");

	return 0;
}
/* Example Execution
Please Enter the RPN expression to be evaluated:
(NOTE: Each digit or operator should be separated by a space and end with :)
2 5 9 * 1 / +:
Token = 2 Push 2
Token = 5 Push 5
Token = 9 Push 9
Token = * Pop 9 Pop 5 Push 45
Token = 1 Push 1
Token = / Pop 1 Pop 45 Push 45
Token = + Pop 45 Pop 2 Push 47
Token = Pop 47
Type 'Y' or 'y' to continue, or type any other letter to quit: y
Please Enter the RPN expression to be evaluated:
(NOTE: Each digit or operator should be separated by a space and end with :)
2 6 * 1 +:
Token = 2 Push 2
Token = 6 Push 6
Token = * Pop 6 Pop 2 Push 12
Token = 1 Push 1
Token = + Pop 1 Pop 12 Push 13
Token = Pop 13
Type 'Y' or 'y' to continue, or type any other letter to quit: q

C:\Users\rsaun\OneDrive\Penn State\Summer 2020\CMPSC 122\assign6\Debug\assign6.exe (process 12764) exited with code 0.
Press any key to close this window . . .
*/