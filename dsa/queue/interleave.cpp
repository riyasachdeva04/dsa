#include <iostream>
using namespace std;
#include<queue>
#include<stack>

void reverse(queue<int> &Q)
{
  if(Q.empty())
    return;
  int temp = Q.front();
  Q.pop();
  reverse(Q);
  Q.push(temp);
}

void interleave(queue<int>& Q)
{
  stack<int> S1;
  stack<int> S2;
  int n = Q.size();
  for(int i=0; i<n/2; i++)
    {
      S1.push(Q.front());
      Q.pop();
    }
  while(!Q.empty())
    {
      S2.push(Q.front());
      Q.pop();
    }

  for(int i=0; i<n; i++)
    {
      if(i%2 == 0)
      {
        Q.push(S2.top());
        S2.pop();
      }
      else
      {
        Q.push(S1.top());
        S1.pop();
      }
    }

  reverse(Q);
  
  
}


int main() {
  queue<int> Q;

  Q.push(10);
  Q.push(20);
  Q.push(30);
  Q.push(40);
  Q.push(50);
  Q.push(60);
  Q.push(70);
  Q.push(80);

  interleave(Q);

  while(!Q.empty())
    { 
      cout << Q.front() << " ";
      Q.pop();
    }
}