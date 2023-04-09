#include <iostream>
#include<vector>
using namespace std;

void solve(int n, int open, int close, string& ans, vector <string>& output)
{
  if(open > 0)
    {
      ans.push_back('{');
      solve(n, open-1, close, ans, output);
      ans.pop_back();
    }
  if(close > open)
    {
      ans.push_back('}');
      solve(n, open, close-1, ans, output);
      ans.pop_back();
    }

  if(close == 0 && open == 0)
    {
      output.push_back(ans);
      return;
    }

  




}



int main() {
  int n = 3;
  int open = n;
  int close = n;
  vector <string> output;
  string ans ;

  solve(n, open, close, ans, output);



  for(int i = 0; i < output.size() ; i++)
  {
    for(int j = 0; j < output[i].size() ; j++)
    {
      cout << output[i][j] ;
    }

    cout << endl;
  }
}