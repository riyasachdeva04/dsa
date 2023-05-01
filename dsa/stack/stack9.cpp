#include <iostream>
using namespace std;
#include<stack>

void insertSorted(stack<int>& s, int target)
{
  if(s.empty())
  {
    s.push(target);
    return;
  }

  if(s.top() >= target)
  {
    s.push(target);
    return;
  }

  int topElement = s.top();
  s.pop();

  insertSorted(s, target);
  
  s.push(topElement);
}

void sortStack(stack<int>& s)
{
  if(s.empty())
  {
    return;
  }
  int topElement = s.top();
  s.pop();

  sortStack(s);

  insertSorted(s, topElement);
}

void printStack(stack<int>& s)
{
  if(s.empty())
    return;
  
  int topElement = s.top();
  cout << topElement << " ";
  s.pop();
  printStack(s);
  s.push(topElement);
}

int main() {
  stack<int> s;
  s.push(5);
  s.push(7);
  s.push(9);
  s.push(11);
  s.push(3);

  sortStack(s);

  printStack(s);
  
}