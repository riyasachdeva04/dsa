
#include <iostream>

using namespace std;

int solve(string &a, char c, int i, int n )
{
    static int ans = 0;
    if(i >= n)
        return ans;

    if(a[i] == c)
        ans = i;
    
    ans = solve(a, c, i+1, n);

}


int main()
{
    string a ="abcddedg";
    char c = 'd';
    int n = a.length();
    int i = 0;

    cout << solve(a, c, i, n);
}