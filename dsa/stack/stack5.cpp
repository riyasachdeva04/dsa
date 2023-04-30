#include <iostream>
using namespace std;
#include<stack>

void insertAtBottom(stack<int>& s, int target)
{
  if(s.empty())
  {
    s.push(target);
    return;
  }

  int topElement = s.top();
  s.pop();
  insertAtBottom(s, target);

  // backtrack
  s.push(topElement);
}

int main() {
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  s.push(60);

  int topElement = s.top();
  s.pop();
  insertAtBottom(s, topElement);

  while(!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
}