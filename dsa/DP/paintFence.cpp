#include <iostream>
using namespace std;

int paintFence(int n, int k)
{
  if(n == 1)
    return k;
  if(n == 2)
    return k + (k*(k-1));

  int ans = (paintFence(n - 1, k) + paintFence(n - 2, k))*(k-1);

  return ans;
}

int main() {

  int n = 4;
  int k = 3;

  cout << paintFence(n, k) << endl;

}