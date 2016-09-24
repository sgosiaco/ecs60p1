#include <fstream>
#include <iostream>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <cstdio>

#include "CPUTimer.h"
#include "LinkedList.h"
#include "CursorList.h"
#include "StackAr.h"
#include "StackLi.h"
#include "QueueAr.h"
#include "SkipList.h"
#include "vector.h"

using namespace std;

vector<CursorNode <int> > cursorSpace(500001);

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


void RunList(char* filename)
{
  List<int> list;

  char temp = ' ', s[256];
  int i = 0;
  ifstream inf(filename);
  inf.ignore(256, '\n');
  while(inf.getline(s, 256, ' '))
  {
    temp = *s;
    s[0] = ' ';
    i = atoi(s);
    if(temp == 'i')
      list.insert(i, list.zeroth());
    else
      if(temp == 'd')
        list.remove(i);
    //cout << temp << " " << i << endl;
  }
  inf.close();
}

void RunCursorList(char* filename)
{
  CursorList<int> cursorList(cursorSpace);

  char temp = ' ', s[256];
  int i = 0;
  ifstream inf(filename);
  inf.ignore(256, '\n');
  while(inf.getline(s, 256, ' '))
  {
    temp = *s;
    s[0] = ' ';
    i = atoi(s);
    if(temp == 'i')
      cursorList.insert(i, cursorList.zeroth());
    else
      if(temp == 'd')
        cursorList.remove(i);
    //cout << temp << " " << i << endl;
  }
  inf.close();
}

void RunStackAr(char* filename)
{
  StackAr<int> stackAr;

  char temp = ' ', s[256];
  int i = 0;
  ifstream inf(filename);
  inf.ignore(256, '\n');
  while(inf.getline(s, 256, ' '))
  {
    temp = *s;
    s[0] = ' ';
    i = atoi(s);
    if(temp == 'i')
      stackAr.push(i);
    else
      if(temp == 'd')
        stackAr.pop();
    //cout << temp << " " << i << endl;
  }
  inf.close();
}

void RunStackLi(char* filename)
{
  StackLi<int> stackLi;

  char temp = ' ', s[256];
  int i = 0;
  ifstream inf(filename);
  inf.ignore(256, '\n');
  while(inf.getline(s, 256, ' '))
  {
    temp = *s;
    s[0] = ' ';
    i = atoi(s);
    if(temp == 'i')
      stackLi.push(i);
    else
      if(temp == 'd')
        stackLi.pop();
    //cout << temp << " " << i << endl;
  }
  inf.close();
}

void RunQueueAr(char* filename)
{

}

void RunSkipList(char* filename)
{

}

void menu()
{
  cout << endl;
  cout << "      ADT Menu" << endl;
  cout << "0. Quit" << endl;
  cout << "1. LinkedList" << endl;
  cout << "2. CursorList" << endl;
  cout << "3. StackAr" << endl;
  cout << "4. StackLi" << endl;
  cout << "5. QueueAr" << endl;
  cout << "6. SkipList" << endl;
  cout << "Your choice >> ";
}


int main(int argc, char** argv)
{
  char* filename = new char[256];
  int choice = 0;
  CPUTimer ct;

  cout << "Filename >> ";
  cin >> filename;
  cin.ignore(256, '\n');
  do
  {
    menu();
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
}
