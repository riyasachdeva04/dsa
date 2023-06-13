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

    void *operator new(size_t size);
    void operator delete(void *p);
    void show()
    {
        cout << latitude << " " << longitude << endl;
    }
};

void *Loc::operator new(size_t size)
{
    void *p;
    cout << "New" << endl;

    p = malloc(size);
    return p;
}

void Loc::operator delete(void *p)
{
    cout << "Delete" << endl;
    free(p);
}

int main()
{
    Loc *p1, *p2;
    p1 = new Loc(1, 2);
    p2 = new Loc(1, 0);

    p1->show();
    p2->show();

    delete p1;
    delete p2;
}