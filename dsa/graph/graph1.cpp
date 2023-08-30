#include <iostream>
#include <vector>
using namespace std;


int main() {
  cout << "Enter no of nodes";
  int n;
  cin >> n;
  cout << "Enter no of edges";
  int e;
  cin >> e;

  vector<vector<int>> adj(n, vector<int>(n, 0));

  for(int i=0; i<e; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u][v] = 1;
    }

  // printing 
  for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++)
        {
          cout << adj[i][j] << " ";
        }
      cout << endl;
    }
}