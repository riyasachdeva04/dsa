#include <iostream>
using namespace std;
#include<string>

// function overloading

class printing
{
  public:
  void print(int a)
  {
    cout << "Integer : " << a << endl;
  }

  void print(double a)
  {
    cout << "Float : " << a << endl;
  }

  void print(double a, int b)
  {
    cout << "Float : " << a << " and Int : " << b << endl;
  }

  void print(string a)
  {
    cout << "String : " << a << endl;
  }
};

int main()
{
  printing p;
  p.print(5);
  p.print(5.5);
  p.print(5.5, 5);
  p.print("riiiwtff");
}