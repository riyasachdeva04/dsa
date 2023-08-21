#include <iostream>
#include<vector>
using namespace std;

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
        return solveUsingRec(nums, n-1, sum);
        }
    }

int main() {
  vector<int> nums = {1, 13, 11, 5};
  cout << canPartition(nums);
}