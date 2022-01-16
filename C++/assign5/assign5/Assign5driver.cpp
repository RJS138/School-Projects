/**
 * cmpsc122 Assignment 5 test file
 * File Name: Assign5driver.cpp
 *
 * Description: This program demonstrates a basic String class that implements
 * dynamic allocation and operator overloading.
 *
 */
 
#include <iostream>
#include "mystring2.h"
using namespace std;


/*************************** Main Program **************************/

int main()
{
  String str1, str2("dog");  // Using constructor for initial strings
  char s1[100], s2[100];              // Some C strings.

  // Print out initial strings

  cout << "Initial values:" << endl;
  cout << "str1 holds \"" << str1 << "\" (length = " << str1.length() << ")" << endl;
  cout << "str2 holds \"" << str2 << "\" (length = " << str2.length() << ")" << endl;

  // Inputs some new strings in them

  cout << "\nEnter a value for str1 (no spaces): ";
  cin >> s1;
  str1 = s1;

  cout << "\nEnter a value for str2 (no spaces): ";
  cin >> s2;
  str2 = s2;
 

  cout << "\nAfter assignments..." << endl;
  cout << "str1 holds \"" << str1 << "\" (length = " << str1.length() << ")" << endl;
  cout << "str2 holds \"" << str2 << "\" (length = " << str2.length() << ")" << endl;

  // Get some elements...

  int i;

  cout << "\nEnter which element of str1 to display: ";
  cin >> i;
  cout << "Element #" << i << " of str1 is '" << str1[i] << "'" << endl;

  cout << "\nEnter which element of str2 to display: ";
  cin >> i;
  cout << "Element #" << i << " of str2 is '" << str2[i] << "'" << endl;

  // Concate some strings

  cout << "\nEnter a value to append to str1 (no spaces): ";
  cin >> s1;
 // str1.append(s1); // Actually, the cstring is converted to String object here by the constructor
  str1 += s1;   // same as above

  cout << "\nEnter a value to append to str2 (no spaces): ";
  cin >> s2;
  str2 += s2;



  cout << "\nAfter appending..." << endl;
  cout << "str1 holds \"" << str1 << "\" (length = " << str1.length() << ")" << endl;
  cout << "str2 holds \"" << str2 << "\" (length = " << str2.length() << ")" << endl;

  // Compare strings...

  cout << "\nComparing str1 and str2..." << endl;

  cout << "\"";

  cout<< str1;   // test the overloading of ostream operator <<

  cout << "\" is ";

  if (str1 < str2) {      // test the overloading of comparison operator <
    cout << "less than";
  } else if (str1 > str2) {
    cout << "greater than";
  } else {
    cout << "equal to";
  }

  cout << " \"";
  cout << str2;
  cout << "\"" << endl;

  cout << "\ntest the = operator, after str1 = str2; "<< endl;

  str1 = str2;

 cout << "str1 holds \"" << str1 << "\" (length = " << str1.length() << ")" << endl;
  cout << "str2 holds \"" << str2 << "\" (length = " << str2.length() << ")" << endl;

  str1 += s1;

  cout << "\nAfter str1 = str1 + s1: "<< endl;

  cout << "str1 holds \"" << str1 << "\" (length = " << str1.length() << ")" << endl;
  cout << "str2 holds \"" << str2 << "\" (length = " << str2.length() << ")" << endl;

  String str3(str2);
  cout << "\ntest the copy constructor, after str4(str3);"<< endl;
   
  cout << "str2 holds \"" << str2 << "\" (length = " << str2.length() << ")" << endl;
  cout << "str3 holds \"" << str3 << "\" (length = " << str3.length() << ")" << endl;

  cout << "\nafter appending str2 by str1" << endl;
  str2 += str1;
  cout << "str2 holds \"" << str2 << "\" (length = " << str2.length() << ")" << endl;
  cout << "str3 holds \"" << str3 << "\" (length = " << str3.length() << ")" << endl;

  cout<< "\nstr3 are not changed. Type any letter to quit." << endl;

  char q;

  cin >> q;

  return 0;
}



