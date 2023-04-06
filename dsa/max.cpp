#include<iostream>
using namespace std;

string solve(string x, int dig, int len)
{
    int ans = x - 'o';
    int a = pow(10,len-1);
    int b = pow(10,len);

    int firstdig = ans / a;
    if(firstdig < dig)
        {
            ans = dig*b ; 
            return ans + '0';
        }
    
    solve(x, dig, len-1);


    
    
}

int main()
{
int t;
cin >> t;
int dig;

vector<string> A[t];

for(int i=0 ; i<t ; i++)
{
    cin >> A[i] >> dig;
    cout << solve(A[i], dig, A[i].size());
}
}