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
Assisted By(Line Numbers): Some of the code was supplied in the lecture and the provided starter code. 
File Name: proj10.cpp
Name: Robert Saunders Jr
PSU User ID: rjs6748
Course Title: CMPSC 122 Summer 2020
Due Time: Sunday July 26, 2020 @ 23:59
Time of Last Modification: Sunday July 26, 2020 @ 22:42
Description: TO understand and use Binary Search Trees. 

THis project is unfinished and in a broken state. I currently get an exception thrown when trying to input into the right side of the tree when the curent state is NULL.
I am not sure if my tree code is in a working condition.
There is no output file because i could not get my program to output a file.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Data stored in the node type
struct WordCount
{
	string word;
	int count = 0;
};
//Node type: 
struct TreeNode 
{
	WordCount info;
	TreeNode* left;
	TreeNode* right;
};

// Two function's prototype
// Increments the frequency count if the string is in the tree
// or inserts the string if it is not there.

void Insert(TreeNode*&, string);
// Prints the words in the tree and their frequency counts.
void PrintTree(TreeNode*, ofstream& );
//Start your main function and the definitions of above two functions.

int main()
{
	string inputFileName, outputFileName;

	//Setup File names from User Input
	std::cout << "Please type the file name: ";
	getline(cin, inputFileName);
	std::cout << " Please give the output text file name: ";
	getline(cin, outputFileName);
	
	TreeNode *tree = NULL;
	ifstream inFile;
	inFile.open(inputFileName.c_str());
	if (inFile.is_open() == true)
	{
		while (!inFile.eof())
		{
			string word;
			inFile >> word;
			if (word.length() < 3)
			{
				return 0;
			}
			else
			{
				Insert(tree, word);
			}
		}
		ofstream outFile;
		outFile.open(outputFileName.c_str());
		if (outFile.is_open())
		{
			PrintTree(tree, outFile);
		}
		else
		{
			std::cout << "Output File Error" << endl;
			return 0;
		}
		inFile.close();
		outFile.close();
		std::cout << "You are done! You can open the file ' " << outputFileName << " '" << " to check." << endl;
	}
	else
	{
		std::cout << "Error Reading Input File" << endl;
		return 0;
	}
	
}

void Insert(TreeNode*& root, string word)
{
	if (word == root->info.word)
	{
		root->info.count++;
	}
	if (root == NULL)
	{
		root = new TreeNode;
		root->left = NULL;
		root->right = NULL;
		root->info.word = word;
		root->info.count = 1;
		return;
	}
	if (word < root->info.word)
		Insert(root->left, word);
	if (word > root->info.word)
		Insert(root->right, word);
}

void PrintTree(TreeNode* t, ofstream& outfile)
{
	if (t != NULL)
	{
		PrintTree(t->left, outfile);
		outfile << t->info.word << " " << t->info.count << endl;
		PrintTree(t->right, outfile);
	}
}
