#include <iostream>
using namespace std;
#include<stack>

int main() {
  string str = "riiibott";
  stack<char> s;

  for(int i=0 ; i<str.length() ; i++)
  {
    s.push(str[i]);
  }

  while(!s.empty())
  {
    cout << s.top();
    s.pop();
  }
}