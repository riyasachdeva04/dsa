#include <iostream>
using namespace std;

class Coordinate
{
  public:
  int x;
  int y;

  Coordinate()
  {
    x = 0;
    y = 0;
  }

  Coordinate(int x, int y)
  {
    this -> x = x;
    this -> y = y;
  }

  istream& operator>>(istream& in, Coordinate& p)
{
    cout << "Enter coordinates: ";
    in >> p.x >> p.y;
    return in;
}

ostream& operator<<(ostream& out, const Coordinate& p)
{
    out << "x = " << p.x << ", y = " << p.y;
    return out;
}



};