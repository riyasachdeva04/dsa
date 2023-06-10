#include <iostream>
using namespace std;
#include<queue>
#include<stack>

  int count = 0; 

  void reverseK(queue<int>& Q, int k, int n)
  {
    stack<int> S;

    if(count == k)
      return;

    int temp = Q.front();
    Q.pop();
    S.push(temp);
    count++;
    reverseK(Q, k, n);
    Q.push(S.top());
    S.pop();
    
  }

  void reverseQueue(queue<int>& Q, int k, int n)
  {
      reverseK(Q, k, n);

    for(int i=0; i<n-k; i++)
      {
        int temp = Q.front();
        Q.pop();
        Q.push(temp);
      }

  }
  
int main() {
  queue<int> Q;
  int k;

  Q.push(3);
  Q.push(6);
  Q.push(9);
  Q.push(12);
  Q.push(15);

  cout << "Enter no of elements to reverse";
  cin >> k;
  int n = Q.size();

  reverseQueue(Q, k, n);

  while(!Q.empty())
    {
      cout << Q.front() << " ";
      Q.pop();
    }
}