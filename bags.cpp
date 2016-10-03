#include <fstream>
#include <iostream>
#include <cstdlib>

#include "StackLi.h"
#include "QueueAr.h"


using namespace std;

int main(int argc, char** argv)
{
  short num;
  StackLi<Queue<int> *> stack;
  if(argc > 1)
  {
    ifstream inf(*(argv + 1));
    argc = atoi(*(argv + 2));
    //cout << argc << endl;
    while(inf >> num)
    {
      if(stack.isEmpty() || stack.top()->isFull())
      {
        //cout << "new ";
        stack.push(new Queue<int> (argc) );
      }

      //cout << num << ' ';
      stack.top()->enqueue(num);
    }
    //cout << endl;
    inf.close();
    while(!stack.isEmpty())
    {
      while(!stack.top()->isEmpty())
      {
        cout << stack.top()->dequeue() << ' ';
      }
      stack.pop();
    }
    cout << endl;
  }
}
