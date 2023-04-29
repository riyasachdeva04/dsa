#include <iostream>
using namespace std;

class Stack
{
  public:
  int* arr;
  int size;
  int top1;
  int top2;

  Stack(int size)
  {
    this->size = size;
    arr = new int[size];
    top1 = -1;
    top2 = size;
  }

  int getTop1()
  {
    return arr[top1];
  }

  int getTop2()
  {
    return arr[top2];
  }

  bool isEmpty()
  {
    if(top1 == -1 && top2 == size)
      return true;
    else
      return false;
  }

  void push1(int data)
  {
    if(top1+1 != top2)
      {
      top1++;
      arr[top1] = data;
      }
    else
      cout << "Cannot push, Stack Overflow" << endl;
  }

  void push2(int data)
  {
    if(top1+1 != top2)
    {
      top2--;
      arr[top2] = data;
    }
    else
      cout << "Cannot push, Stack Overflow" << endl;
  }

void pop1()
{
  if(top1 != -1)
    top1--;
  else
    cout << "Cannot pop, Stack Underflow" << endl;
}

void pop2()
{
  if(top2 != size)
    top2++;
  else
    cout << "Cannot pop, Stack Underflow" <<endl;
}

void print()
{
  cout << "Stack1: ";
  while(top1 != -1)
  {
    cout << arr[top1] << " ";
    pop1();
  }

  cout << endl;

  cout << "Stack2: ";

  while(top2 != size)
  {
    cout << arr[top2] << " ";
    pop2();
  }

  cout << endl;

}
};

int main() {
  Stack st(6);
  st.push1(5);
  st.push1(10);
  st.push1(15);
  st.push2(20);
  st.push2(25);
  st.push2(30);
  st.push2(100);

  st.pop1();
  st.pop2();

  st.print();

}