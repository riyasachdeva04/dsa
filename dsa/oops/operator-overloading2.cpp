#include<iostream>
using namespace std;

class Loc
{
    public:
    int latitude;
    int longitude;
    Loc()
    {
        latitude = 0;
        longitude = 0;
    }

    Loc(int lat, int lng)
    {
        latitude = lat;
        longitude = lng;
    }

    Loc operator +(Loc obj);
    Loc operator -(Loc obj);
    Loc operator =(Loc obj);
    Loc operator ++();
};

Loc Loc::operator +(Loc obj2)
{
    Loc temp;
    temp.latitude = latitude + obj2.latitude;
    temp.longitude = longitude + obj2.longitude;
    return temp;
}

Loc Loc::operator -(Loc obj2)
{
    Loc temp;
    temp.latitude = latitude - obj2.latitude;
    temp.longitude = longitude - obj2.longitude;
    return temp;
}

Loc Loc:: operator =(Loc obj)
{
    latitude = obj.latitude;
    longitude = obj.longitude;
    return *this;
}

Loc Loc::operator ++()
{
    latitude++;
    longitude++;
    return *this;
}



int main()
{
    Loc obj1(2, 3);
    Loc obj2(1,4);
    Loc obj3;
    obj3 = obj1+obj2;
    cout << obj3.latitude << "  " << obj3.longitude;
}