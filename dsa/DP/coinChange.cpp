class Solution {
public:

    int solveRec(vector<int>& coins, int amount)
    {
        if(amount == 0)
            return 0;
        
        if(amount < 0)
            return INT_MAX;
        
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++)
        {
            int ans = solveRec(coins, amount-coins[i]);
            if(ans != INT_MAX)
                mini = min(mini, ans+1);
        }
        return mini;
    }

    int solveMem(vector<int>& coins, int amount, vector<int>& dp)
    {
        if(amount == 0)
            return 0;
        
        if(amount < 0)
            return INT_MAX;

        if(dp[amount] != -1)
        {
            return dp[amount];
        }
        
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++)
        {
            int ans = solveMem(coins, amount-coins[i], dp);
            if(ans != INT_MAX)
                mini = min(mini, ans+1);
        }

        dp[amount] = mini;
        return mini;
    }

    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1, -1);

        int ans = solveMem(coins, amount, dp);
        if(ans == INT_MAX)
            return -1;
        else
            return ans;

    }
};