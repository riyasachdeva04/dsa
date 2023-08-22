class Solution {
public:

    bool solveUsingRec(vector<int>& nums, int n, int sum)
    {
        if(sum == 0)
            return true;

        if(n == 0)
            return false;

        bool include = solveUsingRec(nums, n-1, sum-nums[n]);
        bool exclude = solveUsingRec(nums, n-1, sum);

        bool ans = include || exclude;
        return ans;

    }

    bool solveMem(vector<int>& nums, int n, int sum, vector<vector<int>>& dp)
    {
        if(sum == 0)
            return true;
        if(n <= 0 || sum<0)
            return false;

        if(dp[n][sum] != -1)
            return dp[n][sum];

        bool include = solveMem(nums, n-1, sum-nums[n], dp);
        bool exclude = solveMem(nums, n-1, sum, dp);

        dp[n][sum] = include || exclude;
        return dp[n][sum];        
    }

    bool solveUsingTabulation(vector<int>& nums, int target,  vector<vector<int> >& dp) {
        int n = nums.size();
        
        for(int i=0; i<nums.size(); i++) {
            dp[i][0] = 1;
        }

        for(int index = n-1; index>=0; index--) {
            for(int t = 1; t<=target; t++) {
                bool include = 0;
                if(t-nums[index] >=0)
                    include = dp[index+1][t-nums[index]];

                bool exclude = dp[index+1][t];

                dp[index][t] = (include || exclude);
            }
        }

        return dp[0][target];
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
        }

        if(sum % 2 != 0)
            return false;
        else
        {
        sum = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        return solveUsingTabulation(nums, sum, dp);
        }
    }
};