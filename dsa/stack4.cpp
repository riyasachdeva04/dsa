// middle element
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
    this -> size = size;
    arr = new int[size];
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
  
  int getTop()
  {
    return top;
  }

   void pop()
  {
    if(top != -1)
      top--;
    else
      cout << "Cannot pop, Stack Underflow" << endl;
  }

  void middleElement()
  {

    if(top == -1)
    {
      cout << "Stack is empty";
      return;
    }

    if(top == (size)/2)
    {
      cout << "Middle element: " << arr[top] << endl;
      return;
    }

    // reccursion
    int temp = arr[top];
    pop();
    middleElement();

    // backtracking
    push(temp);

  }

};


int main() {
  Stack s(5);
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  s.middleElement();
}