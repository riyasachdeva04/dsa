class Solution {
public:
    int topDownSolve(int n, vector<int>& dp)
    {
        if(n==1 || n==0)
            return n;

        // check is ans exists
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);
        return dp[n];
        
    }

    int bottomUp(int n)
    {
        vector<int> dp(n+1, -1);

        dp[0] = 0;
        
        if(n==0)
            return dp[0];
        dp[1] = 1;

        

        for(int i=2; i<n+1; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    int fib(int n)
    {
        // int ans = recSolve(n);
        // return ans;

        // 1. Create DP array
        // vector<int> dp(n+1, -1);
        // int ans = topDownSolve(n, dp);
        return bottomUp(n);
    }


};