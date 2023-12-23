class Solution {
public:
    // int solve(vector<int>& prices, int i, bool buy, int flag, vector<vector<vector<int>>>& dp)
    // {
    //     if(flag == 2 || i==prices.size())
    //         return 0;

    //     if(dp[i][buy][flag] != -1)
    //         return dp[i][buy][flag];

    //     int profit = 0;
    //     if(buy)
    //     {
    //         int profitBuy = -prices[i] + solve(prices, i+1, false, flag, dp);
    //         int ignore = solve(prices, i+1, true, flag, dp);
    //         profit = max(profitBuy, ignore);
    //     }
    //     else
    //     {
    //         int profitSell = prices[i] + solve(prices, i+1, true, flag+1, dp);
    //         int ignore = solve(prices, i+1, false, flag, dp);
    //         profit = max(profitSell, ignore);
    //     }
    //     dp[i][buy][flag] = profit;
    //     return dp[i][buy][flag];
    // }

    int solve(vector<int>& prices, vector<vector<vector<int>>>& dp)
    {
        for(int i=prices.size()-1; i>=0; i--)
        {
            for(int buy=0; buy<2; buy++)
            {
                for(int flag = 1; flag<3; flag++)
                {
                    int profit = 0;
                    if(buy)
                    {
                        int profitBuy = -prices[i] + dp[i+1][0][flag];
                        int ignore = dp[i+1][1][flag];
                        profit = max(profitBuy, ignore);
                    }
                    else
                    {
                        int profitSell = prices[i] + dp[i+1][1][flag-1];
                        int ignore = dp[i+1][0][flag];
                        profit = max(profitSell, ignore);
                    }
                    dp[i][buy][flag] = profit;
                }
            }
        }
        return dp[0][1][2];
        
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        return solve(prices, dp);
    }
};