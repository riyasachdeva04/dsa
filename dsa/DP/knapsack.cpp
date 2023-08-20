#include <iostream>
#include<vector>
using namespace std;

// n is last index
int solveUsingRec(vector<int>& wt, vector<int>& val, int n, int cap)
{
  if(n == 0)
  {
    if(wt[n] <= cap)
      return val[n];
    else
      return 0;
  }

  int incl = 0;
  if(wt[n] <= cap)
    incl = val[n] + solveUsingRec(wt, val, n-1, cap-wt[n]);
  
  int excl = solveUsingRec(wt, val, n-1, cap);

  return max(incl, excl);
}

int main() {
  vector<int> weights = {4, 5, 1};
  vector<int> vals = {1, 2, 3};
  int n = 3;
  int cap = 4;
  int ans = solveUsingRec(weights, vals, n-1, cap);
  cout << ans << endl;
}