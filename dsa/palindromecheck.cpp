#include<iostream>
using namespace std;


int counting(int n)
{
    int n1 = n;
    int count = 0;
    for(n1 != 0)
    {
        n1 = n1 / 10;
        count++;
    }
    return count;
}

bool checkPalindrome(int n)
{
    int count = counting(n);

    if(count == 0)
    {
        return;
    }

    if()

}

int main()
{
    int n = 3456543;
    checkPalindrome(n);
}