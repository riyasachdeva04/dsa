#include <iostream>
using namespace std;

class Base //abstract class
{
  public:
  virtual void show() = 0;
};

class Derived : public Base
{
  public:
  void show()
  {
    cout << "Derived fxn";
  }
};


int main() {
Base* b;
Derived d;
b = &d;
b -> show();
}