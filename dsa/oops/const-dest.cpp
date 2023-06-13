#include <iostream>
using namespace std;

class Base
{
  public:
  Base()
  {
    cout << "Base class const" << endl;
  }
  ~Base()
  {
    cout << "Destroy base class " << endl;
  }
};

class Derived : public Base
{
  public:
  Derived()
  {
    cout << "Derived const" << endl;
  }

  ~Derived()
  {
    cout << "Destroy derived class" << endl;
  }
};

int main() {
  Derived d1;
}