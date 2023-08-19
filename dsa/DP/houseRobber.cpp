class Solution {
public:

    int solveRec(vector<int>& nums, int n)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return nums[0];
        
        int include = solveRec(nums, n-2) + nums[n];
        int exclude = solveRec(nums, n-1) + 0;

        int ans = max(include, exclude);
        return ans;
    }

    int solveMem(vector<int>& nums, int n, vector<int>& dp)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return nums[0];

        if(dp[n] != -1)
            return dp[n];

        int include = solveMem(nums, n-2, dp) + nums[n];
        int exclude = solveMem(nums, n-1, dp) + 0;

        dp[n] = max(include, exclude);
        return dp[n];

    }

    int solveTab(vector<int>& nums, int n)
    {
        vector<int> dp(n+1, 0);

        dp[0] = nums[0];

        for(int i=1; i<=n; i++)
        {
            int temp = 0;
            if(i-2 >= 0)
                temp = nums[i-2];

            int include = temp + nums[i];
            int exclude = nums[i-1] + 0;
            dp[i] = max(include, exclude);

        }

        return dp[n];
    }


    int rob(vector<int>& nums) 
    {
        int n = nums.size() - 1;
        // return solveRec(nums, n);

        vector<int> dp(n+1, -1);
        return solveMem(nums, n, dp);
    }
      
};