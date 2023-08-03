#include <iostream>
using namespace std;
#include <unordered_map>

int main() {
  unordered_map<string, int> m;

  // insertion
  pair<string, int> p = make_pair("Car1", 8);
  m.insert(p);
  pair<string, int> p2("Car2", 5);
  m.insert(p2);

  m["Car3"] = 7;

  // access
  cout << m.at("Car1") << endl;
  cout << m["Car2"] << endl;

  // search
  cout << m.count("Car4") << endl;

  if(m.find("Car5") != m.end())
    cout << "Found" << endl;
  else
    cout << "Lost" << endl;

  cout << m.size() << endl;
  cout << m["Car5"] << endl;
  cout << m.size() << endl;
  m["Car5"] = 3;
  cout << m["Car5"] << endl;
  cout << m.size() << endl;

  cout << "Print all entries: " << endl;

  for(auto i: m)
    {
      cout << i.first << " " << i.second << endl;
    }
  
}