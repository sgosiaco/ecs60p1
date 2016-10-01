#include <fstream>
#include <iostream>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <cstdio>

#include "StackLi.h"


using namespace std;

bool checkIfPair(char left, char right)
{
  if(left == '{' && right == '}')
    return true;
  else
    if(left == '(' && right == ')')
      return true;
    else
      if(left == '[' && right == ']')
        return true;
      else
        if(left == '*' && right == '/')
          return true;
  return false;
}

void RunListString(char* filename)
{
  StackLi<char> stackLi;
  StackLi<int> count;

  char s = ' ';
  int i = 1, comment = 0;
  ifstream inf(filename);
  while(inf.get(s))
  {
    //cout << "c:" << s << ' ' << comment << endl;
    if(s == '\0')
      return;
    if(s == '\n')
      i++;
    if(s == '(' || s == '{' || s == '[' || s == '/')
    {
      if(comment == 0)
      {
        if(s == '/')
        {
          inf.get(s);
          if(s == '*')
          {
            comment = 1;
            stackLi.push(s);
            count.push(i);
          }
          else
          {
            if(s == '(' || s == '{' || s == '[')
            {
              stackLi.push(s);
              count.push(i);
            }
          }
        }
        stackLi.push(s);
        count.push(i);
      }
    }
    else
    {
      if(s == ')' || s == '}' || s == ']' || s == '*')
      {
        if(s == '*')
        {
          inf.get(s);
          if(s == '/')
          {
            if(comment == 1)
            {
              comment = 0;
              if(stackLi.isEmpty() || !checkIfPair(stackLi.top(), s))
              {
                cout << "Unmatched " << s << " on line #" << i << endl;
                return;
              }
              else
              {
                stackLi.pop();
                count.pop();
              }
            }
            else
            {
              cout << "Unmatched */ on line #" << i << endl;
              return;
            }
          }
        }
        if(comment == 0 && (s == ')' || s == '}' || s == ']'))
        {
          cout << stackLi.top() << ' ' << s << endl;
          if(stackLi.isEmpty() || !checkIfPair(stackLi.top(), s))
          {
            cout << "Unmatched " << s << " on line #" << i << endl;
            return;
          }
          else
          {
            stackLi.pop();
            count.pop();
          }
        }
      }
    }
  }
  if(comment == 1)
    cout << "Unmatched /* on line #" << count.topAndPop() << endl;
  if(stackLi.isEmpty())
    cout << "OK" << endl;

  inf.close();
}



int main(int argc, char** argv)
{
  char* filename = *(argv + 1);
  if(argc > 1)
    RunListString(filename);
}
