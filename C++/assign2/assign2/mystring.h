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
File Name: mystring.h
Name: Robert Saunders Jr
PSU User ID: rjs6748
Course Title: CMPSC 122 Summer 2020
Due Time: Sunday May 31, 2020 @ 23:59
Time of Last Modification: Sunday May 31, 2020 @ 19:38
Description: This project defines user created functions to mimic those in the cstring library
*/
int mystrlen(const char* s); /* Returns length of string s*/
int mystrcmp(const char* s1, const char* s2); /* Compares the values of s1 and s2 to verify if they are equal*/
char* mystrcpy(char* s1, const char* s2);/* Returns a copy of s2 into char* s1*/
char* mystrcat (char* s1, const char* s2);/* Appends s2 to the end of s1 */
