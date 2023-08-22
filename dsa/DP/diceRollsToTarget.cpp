class Solution {
public:
    int solveUsingRec(int n, int k, int target)
    {
        if(target < 0)
            return 0;
        if(target == 0 && n == 0)
            return 1;
        if(target != 0 && n == 0)
            return 0;
        if(target == 0 && n != 0)
            return 0;

        int ans = 0;
        for(int i=1; i<=k; i++)
        {
            ans += solveUsingRec(n-1, k, target-i);
        }
        return ans;

    }

    int solveMem(int n, int k, int target, vector<vector<long long int>>& dp)
    {
        long long int MOD = 1000000007;

        if(target < 0)
            return 0;
        if(target == 0 && n == 0)
            return 1;
        if(target != 0 && n == 0)
            return 0;
        if(target == 0 && n != 0)
            return 0;

        if(dp[n][target] != -1)
            return dp[n][target];
        
        long long int ans = 0;
        for(int i=1; i<=k; i++)
        {
            long long int recAns = solveMem(n-1, k, target-i, dp);
            ans = (ans%MOD)+(recAns%MOD);
            ans = ans%MOD;
        }
        dp[n][target] = ans;

        return dp[n][target];
    }

    int solveUsingTab(int n, int k, int target)
    {
        long long int MOD = 1000000007;

        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;

        for(int index=1; index<=n; index++)
        {
            for(int t=1; t<=target; t++)
            {
                long long int ans = 0;
                for(int i=1; i<=k; i++)
                {
                    long long int recAns = 0;
                    if(t-i >= 0)
                        recAns = dp[index-1][t-i];
                    ans = (ans%MOD)+(recAns%MOD);
                    ans = ans%MOD;
                }
                dp[index][t] = ans;

            }
        }

        return dp[n][target];
    }

    int SOsoln(int n, int k, int target)
    {
        long long int MOD = 1000000007;

        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] = 1;

        for(int index=1; index<=n; index++)
        {
            for(int t=1; t<=target; t++)
            {
                long long int ans = 0;
                for(int i=1; i<=k; i++)
                {
                    long long int recAns = 0;
                    if(t-i >= 0)
                        recAns = prev[t-i];
                    ans = (ans%MOD)+(recAns%MOD);
                    ans = ans%MOD;
                }
                curr[t] = ans;

            }
            prev = curr;
        }

        return curr[target];
    }

    int numRollsToTarget(int n, int k, int target) {

        // return solveUsingRec(n, k, target);
        // vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, -1));
        return SOsoln(n, k, target);

    }


};