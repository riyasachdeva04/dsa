class Solution {
public:

    int solveUsingRec(int start, int end)
    {
        if(start >= end)
            return 0;
        
        int ans = INT_MAX;

        for(int i=start; i<=end; i++)
        {
            ans = min(ans, i+max(solveUsingRec(start, i-1), solveUsingRec(i+1, end)));
        }
        return ans;
    }

    int solveTab(int n)
    {
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        

            for(int s=n; s>=0; s--)
            {
                for(int e=0; e<=n; e++)
                {
                    int ans = INT_MAX;
                    if(s >= e)
                        continue;
                    else
                    {
                        for(int i=s; i<=e; i++)
                        {
                            ans = min(ans, i+max(solveMemo(s, i-1, dp), solveMemo(i+1, e, dp)));
                        }
                    }

                    dp[s][e] = ans;
                }
            }


        
        return dp[1][n];
    }

    int solveMemo(int start, int end, vector<vector<int>>& dp)
    {
        if(start >= end)
            return 0;

        if(dp[start][end] != -1)
            return dp[start][end];
        
        int ans = INT_MAX;

        for(int i=start; i<=end; i++)
        {
            ans = min(ans, i+max(solveMemo(start, i-1, dp), solveMemo(i+1, end, dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }



    int getMoneyAmount(int n) {

        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));

        int ans = solveTab(n);
        return ans;
        
    }
};