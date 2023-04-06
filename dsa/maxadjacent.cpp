
#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

void solve(vector<int>& arr, int sum, int i,int& maxi)
{
    if(i >= arr.size()){
        maxi = max(sum, maxi);
        return;
    }
    
    // exclude
    solve(arr, sum, i+1, maxi);
    
    // include
    solve(arr, sum+arr[i], i+2, maxi);
    
}

int main()
{
    vector<int> v = {2, 1, 4, 9};
    
    int sum = 0;
    int i =0;
    int maxi = 0;
    solve(v, sum, i, maxi);
    
    cout << maxi <<endl;
    
    
}