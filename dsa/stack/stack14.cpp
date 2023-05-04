#include <iostream>
using namespace std;
#include<stack>
#include<vector>

int main() {
  vector<int> v;
  v.push_back(2);
  v.push_back(1);
  v.push_back(4);
  v.push_back(3);

  vector<int> ans(v.size());
  stack<int> st;
  st.push(-1);

  for(int i=0 ; i<v.size() ; i++)
  {
    while(v[i] < st.top())
    {
      st.pop();
    }

    ans[i] = st.top();
    st.push(v[i]);
  }

  for(int i=0 ; i<ans.size() ; i++)
  {
    cout << ans[i] << " ";
  }

}