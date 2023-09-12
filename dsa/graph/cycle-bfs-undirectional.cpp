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

  bool checkCycleBFS(int src, unordered_map<int, bool>& vis)
  {
    unordered_map<int, int> parent;
    queue<int> Q;

    Q.push(src);
    parent[src] = -1;
    vis[src] = true;

    while(!Q.empty())
    {
      int frontNode = Q.front();
      Q.pop();
      
      for(auto nbr:adjList[frontNode])
      {
        if(vis[nbr] != true)
        {
          Q.push(nbr);
          parent[nbr] = frontNode;
          vis[frontNode] = true;
        }
        else
        {
          if(nbr != parent[frontNode])
            return true;
        }
      }
    }
    return false;
  }
};

int main() {

  Graph g;
  g.addEdge(0, 1, 0);
  g.addEdge(0, 3, 0);
  g.addEdge(1, 2, 0);
  g.addEdge(3, 4, 0);
  g.addEdge(2, 4, 0);

  unordered_map<int, bool> vis;
  if(g.checkCycleBFS(0, vis))
    cout << "Cycle is present";
  else
    cout << "Cycle absent";
}