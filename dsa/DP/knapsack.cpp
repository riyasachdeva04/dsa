#include <iostream>
#include<vector>
using namespace std;

//  n= last index
int solveUsingRec(vector<int>& weights, vector<int>& value, int n, int capacity)
{
  if(n == 0)
  {
    if(weights[0] <= capacity)
    {
      return value[0];
    }
    else
      return 0;
  }

  int include = 0;
  if(weights[n] <= capacity)
  {
    include = value[n] + solveUsingRec(weights, value, n-1, capacity-weights[n]);
    
  }
  int exclude = solveUsingRec(weights, value, n-1, capacity);

  int ans = max(include, exclude);
  return ans;
}

// n is last index
int solveMem(vector<int>& weights, vector<int>& value, int n, int capacity, vector<vector<int>>& dp)
{
  if(n == 0)
  {
    if(weights[n] <= capacity)
      return value[n];
  }

  if(dp[n][capacity] != -1)
    return dp[n][capacity];
  
  int include = 0;
  if(weights[n] <= capacity)
  {
    include = value[n] + solveUsingRec(weights, value, n-1, capacity-weights[n]);
    
  }
  int exclude = solveUsingRec(weights, value, n-1, capacity);

  dp[n][capacity] = max(include, exclude);
  return dp[n][capacity];
}

// n is the last index
int solveUsingTab(vector<int>& weights, vector<int>& value, int n, int capacity)
{
  vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

  for(int w=weights[0]; w<=capacity; w++)
    {
      if(weights[0] <= capacity)
        dp[0][w] = value[0];
    }

  for(int index=1; index<=n; index++)
    {
      for(int wt = 0; wt<=capacity; wt++)
        {
          int include = 0;
          if(weights[index] <= wt)
          {
            include = value[index] + dp[index-1][wt-weights[index]];
            
          }
          int exclude = dp[index-1][wt];

          dp[index][wt] = max(include, exclude);
        }
    }
  return dp[n][capacity];
}
int main() {
  vector<int> weights = {4, 5, 1};
  vector<int> value = {1, 2, 3};
  int n = 3;
  int cap = 4;

  // vector<vector<int>> dp(n, vector<int>(cap+1, -1));
  
  cout << solveUsingTab(weights, value, n-1, cap);
}