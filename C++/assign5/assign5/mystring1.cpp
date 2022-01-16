//File: mystring1.cpp
// Implementation file for user-defined String class.

#include "mystring1.h"


String::String()
{
  contents[0] = '\0';
  len = 0;
}

String::String(const char s[])
{
  len = strlen(s);
  strcpy_s(contents, s);
}



void String::append(const String &str)
{
  strcat_s(contents, str.contents);

  len += str.len;

}


bool String::operator >(const String &str) const
{
  return strcmp(contents, str.contents) > 0;
}

bool String::operator <(const String &str) const
{
  return strcmp(contents, str.contents) < 0;
}


String String::operator +=(const String &str)
{
	append(str);
	return *this;
}

void String::print(ostream &out) const
{
  out << contents;
}

int String::length() const
{
  return len;
}

char String::operator [](int i) const
{
  if (i < 0 || i >= len) {
    cerr << "can't access location " << i
         << " of string \"" << contents << "\"" << endl;
    return '\0';
  }
  return contents[i];
}

ostream & operator<<(ostream &out, const String & s) // overload ostream operator "<<" - External!
{ 
	s.print(out);
	return out;
}

