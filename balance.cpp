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
  int i = 1, comment = 0, asterix = 0;
  ifstream inf(filename);
  while(inf.get(s))
  {
    //cout << "c:" << s << ' ' << comment << endl;
    if(s == '\0')
      return;
    if(s == '\n')
      i++;
    if(s == '(' || s == '{' || s == '[' || s == '/' || s == '*')
    {
      if(comment == 0)
      {
        if(s == '/')
          comment = 1;
        if(s != '*')
        {
          stackLi.push(s);
          count.push(i);
        }
      }
      else
      {
        //cout << "FIRST " << s << ' ' << stackLi.top() << endl;
        if(s == '*' && stackLi.top() == '/')
        {
          while(inf.get(s))
          {
            //cout << 'W' << s << ' ' << asterix << endl;
            if(s == '*')
              asterix = 1;
            else
            {
              if(asterix == 1 && s == '/')
              {
                asterix = 0;
                comment = 0;
                stackLi.pop();
                count.pop();
                break;
              }
              else
                if(s != '\n')
                  asterix = 0;
            }
          }
          if(inf.eof())
          {
            cout << "Unmatched /* on line #" << count.topAndPop() << endl;
            comment = 0;
          }
        }
        else
        {
          stackLi.pop();
          count.pop();
          comment = 0;
          if(s == '(' || s == '{' || s == '[')
          {
            stackLi.push(s);
            count.push(i);
          }
        }
      }
    }
    else
    {
      if(s == ')' || s == '}' || s == ']')
      {
        if(comment == 0)
        {
          //cout << stackLi.top() << ' ' << s << endl;
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
    cout << "Unmatched */ on line #" << count.topAndPop() << endl;
  if(stackLi.isEmpty())
    cout << "OK" << endl;
  else
    if(!count.isEmpty())
      cout << "Unmatched " << stackLi.topAndPop() << " on line #" << count.topAndPop() << endl;

  inf.close();
}



int main(int argc, char** argv)
{
  char* filename = *(argv + 1);
  if(argc > 1)
    RunListString(filename);
}
