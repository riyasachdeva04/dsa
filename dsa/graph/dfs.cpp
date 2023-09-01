#include <iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class Graph
{
  public:
  unordered_map<int, list<int>> adjList;

  void addEdge(int u, int v, bool dir)
  {
    adjList[u].push_back(v);

    if(dir == 0)
    {
      adjList[v].push_back(u);
    }
  }

  void printAdjList()
  {
    for(auto node:adjList)
      {
        cout << node.first << "->" ;

        for(auto neighbour:node.second)
          {
            cout << neighbour << ", ";
          }
        cout << endl;
      }
  }

  void bfs(int src, unordered_map<int, bool>& visited)
  {
    queue<int> Q;
    

    Q.push(src);
    visited[src] = true;
    
    while(!Q.empty())
      {
        int frontNode = Q.front();
        cout << frontNode << ", ";
        for(auto neighbour: adjList[frontNode])
          {
            if(!visited[neighbour])
            {
              Q.push(neighbour);
              visited[neighbour] = true;
            }
          }
        Q.pop();
      }
  }

  void dfs(int src, unordered_map<int, bool>& visited)
  {
    cout << src << ", ";
    for(auto neighbour: adjList[src])
      {
        if(!visited[neighbour])
        {
          dfs(neighbour, visited);
          visited[neighbour] = true;
        }
      }
  }
};

int main() {

  Graph g;
  g.addEdge(0, 1, 1);
  g.addEdge(1, 3, 1);
  g.addEdge(0, 2, 1);
  g.addEdge(2, 4, 1);

  unordered_map<int, bool> visited;

  for(int i=0; i<=4; i++)
    {
      if(!visited[i])
        g.dfs(i, visited);
    }


}