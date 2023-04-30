#include <iostream>
using namespace std;
#include<stack>

int temp;
void lastElement(stack<int>& s)
{
  if(!s.empty())
  {
    temp = s.top();
    s.pop();
    lastElement(s);
    s.push(temp);
  }
  
}


int main() {
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  s.push(60);

  lastElement(s);

  cout << temp;
  
  while(!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
}