class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int> ans;
        // Write Your Code here
        sort(candies, candies+N);
        
        int cost1=0;
        int cost2=0;
        int end=N-1;
        for(int i=0; i<N; i++){
            cost1 += candies[i];
            cost2 += candies[end];
            N -= K;
            end--;
        }
        ans.push_back(cost1);
        ans.push_back(cost2);
        return ans;
    }
};