#include <iostream>
#include<vector>
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

int solveMem(int n, int k, vector<int>& dp)
{
    if(n == 1)
      return k;
    if(n == 2)
      return (k + k*(k-1));
    
    if(dp[n] != -1)
      return dp[n];
  
    dp[n] = (solveMem(n - 1, k, dp) + solveMem(n - 2, k, dp))*(k-1);
  
    return dp[n];
}

int solveusingTab(int n, int k)
{
  vector<int> dp(n+1, 0);
  dp[1] = k;
  dp[2] = k + k*(k-1);

  for(int i=3; i<=n; i++)
    {
      dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
    }

  return dp[n];
}

int spaceOptim(int n, int k)
{
  int prev2 = k;
  int prev1 = k + k*(k-1);
  int curr;

  for(int i=3; i<=n; i++)
    {
      curr = (prev1 + prev2) * (k-1);

      prev2 = prev1;
      prev1 = curr;
    }

  return curr; 
}

int main() {

  int n = 4;
  int k = 3;

  // cout << paintFence(n, k) << endl;

  // vector<int> dp(n+1, -1);
  // cout << solveMem(n, k, dp) << endl;

  cout << spaceOptim(n, k) << endl;
  

}