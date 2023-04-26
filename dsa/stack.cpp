#include <iostream>
using namespace std;
#include<stack>

int main() {
  // creation
  stack<int> st;
  st.push(50);
  st.push(60);
  st.push(70);
  st.pop();
  cout << "Element on top: " << st.top() << endl;
  cout << "Element size: " << st.size() << endl;
  if(st.empty())
    cout << "Stack is empty" << endl;
  else
    cout << "Stack is not empty" << endl;

}

