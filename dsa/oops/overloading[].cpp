#include<iostream>
using namespace std;

class Access
{
    public:
    int a[3];

    Access(int x, int y, int z)
    {
        a[0] = x;
        a[1] = y;
        a[2] = z;
    }

    int operator[](int i)
    {
        return a[i];
    }
};

int main()
{
    Access obj(1, 2, 3);
    cout << obj[0];
}