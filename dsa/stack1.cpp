#include <iostream>
using namespace std;

class Stack
{
  public:
  int* arr;
  int top;
  int size;

  Stack(int size)
  {
    arr = new int[size];
    this->size = size;
    top = -1;
  }

  void push(int data)
  {
    if(top < size-1)
    {
    top++;
    arr[top] = data;
    }
    else
    cout << "Cannot push, Stack Overflow" << endl;
  }

  void pop()
  {
    if(top != -1)
    top--;
    else
    cout << "Cannot pop, Stack Underflow" << endl;
  }

  int getTop()
  {
    return arr[top];
  }

  int getSize()
  {
    return size;
  }

  bool isEmpty()
  {
    if(top == -1)
      return true;
    else
      return false;
  }
};

int main() {
  Stack s(5);
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  s.push(60);
  s.pop();
  while(!s.isEmpty())
  {
    cout << s.getTop() << " ";
    s.pop();
  }
}