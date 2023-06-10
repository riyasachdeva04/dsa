#include <iostream>
using namespace std;
#include<queue>

  void reverseQueue(queue<int>& Q)
  {
    if(Q.empty())
      return;

    int t = Q.front();
    Q.pop();
    reverseQueue(Q);
    Q.push(t);
  }
  
int main() {
  queue<int> Q;

  Q.push(10);
  Q.push(20);
  Q.push(30);
  Q.push(40);

  reverseQueue(Q);

  while(!Q.empty())
    {
      cout << Q.front() << " ";
      Q.pop();
    }
}