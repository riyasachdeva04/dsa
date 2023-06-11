#include <iostream>
using namespace std;
#include<string>
#include<queue>

void firstNonRepeating(string& str)
{
  int n = str.length();
  
  queue<char> Q;

  Q.push(str[0]);


  for(int i=1; i<n; i++)
    {
      if(Q.empty())
        cout << "#";
      else
        cout << Q.front();

      if(str[i] == Q.front())
        Q.pop();
      else
        Q.push(str[i]);
    }

  if(Q.empty())
    cout << "#";
  else
    cout << Q.front();
}

int main() {
  string str = "abca";
  firstNonRepeating(str);
}