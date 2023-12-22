class Solution {
public:
    int numSquareHelper(int n, vector<int>& dp)
    {
        if(n==0) return 1;
        if(n<0) return 0;

        if(dp[n] != -1)
            return dp[n];

        int i=1;
        int end = sqrt(n);
        int ans = INT_MAX;

        while(i<=end)
        {
            int perfectSquare = i*i;
            int noOfPerfectSquares = 1 + numSquareHelper(n-(i*i), dp);
            if(noOfPerfectSquares < ans)
            {
                ans = noOfPerfectSquares;
            }
            i++;
        }
        // return ans;
        dp[n] = ans;
        return dp[n];
    }

    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return numSquareHelper(n, dp)-1;
    }
};