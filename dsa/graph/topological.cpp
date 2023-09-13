#include <iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<stack>
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

  void topoSort(int src, unordered_map<int, bool>& visited, stack<int>& S)
  {
    for(auto neighbour: adjList[src])
      {
        if(!visited[neighbour])
        {
          topoSort(neighbour, visited, S);
          visited[neighbour] = true;
        }
      }
    S.push(src);
  }
};

int main() {

  Graph g;
  g.addEdge(0, 1, 1);
  g.addEdge(1, 2, 1);
  g.addEdge(2, 3, 1);
  g.addEdge(3, 4, 1);
  g.addEdge(3, 5, 1);
  g.addEdge(4, 6, 1);
  g.addEdge(5, 6, 1);
  g.addEdge(6, 7, 1);

  unordered_map<int, bool> visited;
  stack<int> S;
  
  g.topoSort(0, visited, S);

  while(!S.empty())
  {
    cout << S.top();
    S.pop();
  }


}