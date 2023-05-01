#include <iostream>
using namespace std;
#include<stack>

bool validExpression(string& s)
{
  stack<char> st;
  bool flag = false;
  
  for(int i=0; i<s.length(); i++)
  {
    char ch = s[i];

    if(ch == '(')
    {
      st.push(ch);
    }

    if(ch == '+' || ch == '-' || ch == '/' || ch == '*')
    {
      flag = true;
    }

    if(ch == ')')
    {
      char topEl = st.top();
      if(flag == true && topEl == '(')
      {
        st.pop();
        flag = false;
      }
      else
        return false;
      
    }
    
  }

  if(st.empty())
    return true;
  else
    return false;
}

int main() {
  string s = "((a+b))";
  cout << validExpression(s);
}