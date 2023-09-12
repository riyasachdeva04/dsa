#include <iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class Graph
{
  unordered_map<int, list<int>> adjList;

  public:
  void addEdge(int u, int v, bool dir)
  {
    adjList[u].push_back(v);

    if(dir == 0)
      adjList[v].push_back(u);
  }

  void printAdjList()
  {
    for(auto node: adjList)
      {
        cout << node.first << "->";
        for(auto neighbour:node.second)
          cout << neighbour << ", ";
        cout << endl;
      }
  }

  bool checkCycleDFS(int src, unordered_map<int, bool>& vis, unordered_map<int, bool>& dfsVis)
  {
    vis[src] = true;
    dfsVis[src] = true;

    for(auto i: adjList[src])
    {
      if(vis[i] != true)
      {  
        int checkAns = checkCycleDFS(i, vis, dfsVis);
        if(checkAns == true)
          return true;
      }
      else if(dfsVis[i] == true)
      {
        return true;
      }
      
    }

    dfsVis[src] = false;
    return false;
  }
};

int main() {

  Graph g;
  g.addEdge(0, 1, 1);
  g.addEdge(1, 2, 1);
  g.addEdge(2, 3, 1);
  g.addEdge(2, 4, 1);
  g.addEdge(3, 4, 1);
  g.addEdge(2, 5, 1);
  g.addEdge(5, 6, 1);
  g.addEdge(6, 7, 1);
  g.addEdge(7, 8, 1);
  g.addEdge(6, 9, 1);



  unordered_map<int, bool> vis;
  unordered_map<int, bool> dfsVis;

  if(g.checkCycleDFS(0, vis, dfsVis))
    cout << "Cycle is present";
  else
    cout << "Cycle absent";
}