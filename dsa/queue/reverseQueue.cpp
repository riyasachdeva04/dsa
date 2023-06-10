#include <iostream>
using namespace std;
#include<stack>
#include<queue>

int main() {
  queue<int> Q;
  stack<int> S;
  Q.push(10);
  Q.push(20);
  Q.push(30);
  Q.push(40);

  while(!Q.empty())
    {
      S.push(Q.front());
      Q.pop();
    }
  while(!S.empty())
    {
      Q.push(S.top());
      S.pop();
    }
  while(!Q.empty())
    {
      cout << Q.front() << " ";
      Q.pop();
    }
}