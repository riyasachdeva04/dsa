class Solution {
public:

    int minCostHelper(vector<int>& days, vector<int>& costs, int i, vector<int>& dp)
    {
        if(i >= days.size()) return 0;
        if(dp[i] != -1)
            return dp[i];
        
        // cost for day1 pass
        int cost1 = costs[0] + minCostHelper(days, costs, i+1, dp);

        // 7 day pass
        int endDay = days[i]+7-1;
        int j=i;
        while(j<days.size() && days[j]<=endDay)
        {
            j++;
        }
        int cost7 = costs[1] + minCostHelper(days, costs, j, dp);

        // 30 day pass
        endDay = days[i]+30-1;
        j=i;
        while(j<days.size() && days[j]<=endDay)
        {
            j++;
        }
        int cost30 = costs[2] + minCostHelper(days, costs, j, dp);

        dp[i] = min(cost1, min(cost7, cost30));
        return dp[i];
    }

    // bottom up solution
    // int minCostHelper(vector<int>& days, vector<int>& costs, int i, vector<int>& dp)
    // {
    //     // if(i >= days.size()) return 0;
    //     dp[days.size()] = 0;

    //     for(int i=(days.size()-1); i>=0; i--)
    //     {   
    //         // cost for day1 pass
    //         int cost1 = costs[0] + dp[i+1];

    //         // 7 day pass
    //         int endDay = days[i]+7-1;
    //         int j=i;
    //         while(j<days.size() && days[j]<=endDay)
    //         {
    //             j++;
    //         }
    //         int cost7 = costs[1] + dp[j];

    //         // 30 day pass
    //         endDay = days[i]+30-1;
    //         j=i;
    //         while(j<days.size() && days[j]<=endDay)
    //         {
    //             j++;
    //         }
    //         int cost30 = costs[2] + dp[j];

    //         dp[i] = min(cost1, min(cost7, cost30));

    //     }
    //     return dp[0];
    // }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1, -1);
        return minCostHelper(days, costs, 0, dp);
    }
};