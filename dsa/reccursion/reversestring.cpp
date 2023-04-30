// reverse a string recursively

#include <iostream>
using namespace std;

void solve(string& s, int i, int n)
{
    if(i > n)
        return;
    
    char temp = s[i];
    s[i] = s[n-1];
    s[n-1] = temp;
    
    solve(s, i+1, n-1);
}

int main()
{
    string str = "riya";
    int i = 0;
    int n = str.length();
    
    solve(str, i, n);
    
    cout << str;
}