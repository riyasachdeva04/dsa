#include <iostream>
using namespace std;

class Base
{
  public:
  int i;
};

class Derived1 : virtual public Base
{
  public:
  int j;
};

class Derived2 : virtual public Base
{
  public:
  int k;
};

class Derived3 : public Derived1, public Derived2
{
  
};


int main() {
  Derived3 ob;
  ob.i = 50;
  cout << ob.i;
}