#include<iostream>
using namespace std;

class loc
{
    public:
    int latitude;
    int longitude;
    loc(){};
    loc(int ltd, int lng)
    {
        latitude = ltd;
        longitude = lng;
    }

    loc operator+(loc obj)
    {
        loc temp;
        temp.latitude = latitude + obj.latitude;
        temp.longitude = longitude + obj.longitude;
        return temp;
    }

    loc operator()(int ltd, int lng)
    {
        loc temp;
        temp.latitude = ltd;
        temp.longitude = lng;
        return temp;
    }
};

int main()
{
    loc obj1(1, 2);
    loc obj2(2, 4);
    loc obj3;
    obj3 = obj1 + obj2(1, 2);
    cout << "obj3 loc: " << obj3.latitude << " " << obj3.longitude;
}