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

void RunListCHAR(char* filename)
{
  StackLi<char> stackLi;
  StackLi<int> count;

  char temp = ' ', store = ' ', oldC = ' ';
  int i = 1, comment = 0, asterix = 0, paren = 0, brace = 0, bracket = 0, debug = 0, line = 0, oldL = 0;
  ifstream inf(filename);
  while(inf.get(temp))
  {
    switch (temp)
    {
      case '\n':
         i++;
        break;
      case '/':
        comment = 1;
        break;
      case '*':
        asterix = 1;
        break;
      case '(':
        stackLi.push(temp);
        count.push(i);
        break;
      case '{':
        stackLi.push(temp);
        count.push(i);
        break;
      case '[':
        stackLi.push(temp);
        count.push(i);
        break;

      case ')':
        stackLi.push(temp);
        count.push(i);
        break;
      case '}':
        stackLi.push(temp);
        count.push(i);
        break;
      case ']':
        stackLi.push(temp);
        count.push(i);
        break;
    }
    //cout << temp;
    //temp = *s;
    //s[0] = ' ';
    //i = atoi(s);
    //cout << temp << " " << i << endl;
  }
  //cout << endl;
  if(debug == 1)
  {
    while(stackLi.isEmpty() != 1)
      cout << count.topAndPop() << stackLi.topAndPop();
    cout << endl;
  }
  else
  {
    while(!stackLi.isEmpty())
    {
      store = stackLi.topAndPop();
      line = count.topAndPop();
      cout << "c:" << store << " line:" << line << endl;
      switch(store)
      {
        case '/':
          comment = 1;
          break;
        case '*':
          asterix = 1;
          break;
        case '(':
          if(paren != 1)
          {
            cout << "Unmatched " << oldC << " on line #" << oldL << endl;
            return;
          }
          else
            paren = 0;
          break;
        case '{':
          if(brace != 1)
          {
            cout << "Unmatched " << oldC << " on line #" << oldL << endl;
            return;
          }
          else
            brace = 0;
          break;
        case '[':
          if(bracket != 1)
          {
            cout << "Unmatched " << oldC << " on line #" << oldL << endl;
            return;
          }
          else
            bracket = 0;
          break;

        case ')':
          paren = 1;
          break;
        case '}':
          if(brace == 1)
          {
            cout << "Unmatched " << oldC << " on line #" << oldL << endl;
            return;
          }
          brace = 1;
          break;
        case ']':
          bracket = 1;
          break;
      }
      oldC = store;
      oldL = line;
    }
  }

  cout << "OK" << endl;
  inf.close();
}

void RunListString(char* filename)
{
  StackLi<char*> stackLi;
  StackLi<int> count;

  char temp = ' ';
  char* s = new char[256];
  int i = 0;
  ifstream inf(filename);
  while(inf.getline(s, 256))
  {
    cout << s << endl;
    //temp = *s;
    //s[0] = ' ';
    //i = atoi(s);
    stackLi.push(s);
    count.push(++i);
    //cout << temp << " " << i << endl;
  }
  while(count.isEmpty() != 1)
    cout << count.topAndPop() << ' ' << stackLi.topAndPop() << endl;
  inf.close();
}



int main(int argc, char** argv)
{
  char* filename = *(argv + 1);
  if(argc > 1)
    RunListCHAR(filename);
}
