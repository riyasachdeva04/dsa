class Solution {
public:
    int solve(vector<int>& prices, int i, bool buy, vector<vector<int>>& dp)
    {
        if(i>=prices.size()) return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;
        if(buy)
        {
            int profitBuy = -prices[i] + solve(prices, i+1, false, dp);
            int ignore = 0 + solve(prices, i+1, true, dp);
            profit = max(profitBuy, ignore);
        }
        else
        {
            int profitSell = prices[i] + solve(prices, i+1, true, dp);
            int ignore = 0 + solve(prices, i+1, false, dp);
            profit = max(profitSell, ignore); 
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }

    // int solve(vector<int>& prices, vector<vector<int>>& dp)
    // {
    //     // if(i>=prices.size()) return 0;
    //     for(int i=prices.size()-1; i>=0; i--)
    //     {
    //         for(int buy=0; buy<2; buy++)
    //         {
    //             int profit = 0;
    //             if(buy)
    //             {
    //                 int profitBuy = -prices[i] + dp[i+1][0];
    //                 int ignore = 0 + dp[i+1][1];
    //                 profit = max(profitBuy, ignore);
    //             }
    //             else
    //             {
    //                 int profitSell = prices[i] + dp[i+1][1];
    //                 int ignore = 0 + dp[i+1][0];
    //                 profit = max(profitSell, ignore); 
    //             }
    //             dp[i][buy] = profit;
    //         }
    //     }
        
    //     return dp[0][1];
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return solve(prices, 0, true, dp);
    }
};