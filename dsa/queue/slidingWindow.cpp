#include <iostream>
using namespace std;
#include<deque>

void slidingWindow(int arr[], int n, int k)
{
  deque<int> Q;
  for(int i=0; i<k; i++)
    {
      if(arr[i] < 0)
        Q.push_back(i);
    }
  for(int i=k ; i<n; i++)
    {
      if(!Q.empty())
        cout << Q.front() << endl;
      else
        cout << "0" << endl;

      while(!Q.empty() && (i-Q.front())>=k)
        Q.pop_front();

      if(arr[i] < 0 ) 
        Q.push_back(i);
    }
  

  if(!Q.empty())
    cout << Q.front() << endl;
  else
    cout << "0" << endl;
  
  
}

int main() {
  int arr[8] = {12, -1, -7, 8, -15, 30, 16, 28};
  int k =3;
  slidingWindow(arr, 8, k);
  
}