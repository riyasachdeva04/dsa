// bfs

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph
{
public:
unordered_map<int, list<int>> adjList;

void addEdge(int u, int v, bool dir)
{
  adjList[u].push_back(v);

  if(dir == 0)
    adjList[v].push_back(u);
}

void printGraph()
{
  for(auto node:adjList)
    {
      cout << node.first << "->";

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
    cout << frontNode << " ";
    for(auto neighbour : adjList[frontNode])
      {
        if(visited[neighbour] != true)
        {
          Q.push(neighbour);
          visited[neighbour] = true;
        }
      }
    Q.pop();
  }
  
}


};

int main()
{
  Graph q;
  q.addEdge(0, 1, 0);
  q.addEdge(1, 2, 0);
  q.addEdge(1, 3, 0);
  q.addEdge(3, 5, 0);
  q.addEdge(3, 6, 0);
  q.addEdge(6, 4, 0);
  q.addEdge(4, 7, 0);

  q.printGraph();

  unordered_map<int, bool> visited;
  for(int i=0; i<=7; i++)
  {
    if(!visited[i])
        q.bfs(i, visited);
  }
  
}