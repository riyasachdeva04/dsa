#include <iostream>
using namespace std;

class Time
{
  public:
  int hrs;
  int mins;


  Time& operator =(int duration)
  {
    hrs = duration / 60;
    mins = duration % 60;
    return *this;
  }

  void show()
  {
    cout << "hrs: " << hrs << " mins: " << mins << endl;
  }
};

int main() {
  Time t1;
  int duration1 = 120;
  cout << "Duration: ";
  cin >> duration1;
  t1 = duration1;
  t1.show();
}

