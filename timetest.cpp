#include "CPUTimer.h"
#include <fstream>
#include <iostream>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int TEN = 10;
const int ASCII_ZERO = '0';
const int ERROR = -1;

int getNumber()
{
  long long number = 0, OK = 1;
  char c;

  for(c = cin.get(); isspace(c) && c != '\n'; c = cin.get());

  if(isdigit(c))
  {
    do
    {
      number = number * TEN + c - ASCII_ZERO;
      c = cin.get();
    }  while(isdigit(c) && number <= INT_MAX);

    while(c != '\n' && isspace(c))
      c = cin.get();

    if(c != '\n' || number > INT_MAX)
      OK = 0;
  }  // if first non-space is a digit
  else // first non-space is not a digit
    OK = 0;  // false

  while(c != '\n')
    c = cin.get();

  if(OK)
    return number;
  else  // invalid number
    return ERROR;

} // getNumber()


void RunList(string filename)
{

}

void RunCursorList(string filename)
{

}

void RunStackAr(string filename)
{

}

void RunStackLi(string filename)
{

}

void RunQueueAr(string filename)
{

}

void RunSkipList(string filename)
{

}


int main(int argc, char** argv)
{
  char temp;
  char s[256];
  string filename = argv[1];
  int i = 0, choice = 0;
  CPUTimer ct;

  do
  {
    choice = getNumber();
    ct.reset();
    switch (choice)
    {
      case 1: RunList(filename); break;
      case 2: RunCursorList(filename); break;
      case 3: RunStackAr(filename); break;
      case 4: RunStackLi(filename); break;
      case 5: RunQueueAr(filename); break;
      case 6: RunSkipList(filename); break;
    }

    cout << "CPU time: " << ct.cur_CPUTime() << endl;
  } while(choice > 0);


  //File handling stuff

  if(!(argc > 1))
  {
    cout << "TEMP ERROR" << endl;
    return -1;
  }

  ifstream inf(argv[1]);
  inf.ignore(256, '\n');
  while(inf.getline(s, 256, ' '))
  {
    temp = *s;
    s[0] = ' ';
    i = atoi(s);
    cout << s << " " << i << endl;
  }

  inf.close();

  //End file handling stuff
}
