#include <iostream>
using namespace std;

// Unary - overloading

class Distance
{
  public:
  int feet;
  int inch;

  Distance()
  {
    feet = 0;
    inch = 0;
  }

  Distance(int F, int I)
  {
    feet = F;
    inch = I;
  }

  Distance operator -()
  {
    feet = -feet;
    inch = -inch;
  }
};

int main() {
  Distance d(4, 2);
  -d;
  cout << d.feet << " " << d.inch;
}