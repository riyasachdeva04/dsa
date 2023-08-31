#include <iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph
{
public:
unordered_map<int, list<pair<int, int>>> adjList;

void addEdge(int u, int v, int weight, bool direction)
{
  adjList[u].push_back({v, weight});

  if(direction == 0)
    adjList[v].push_back({u, weight});
  
}

void printAdjList()
{
  for(auto node:adjList)
    {
      cout << node.first << "->";

      for(auto neighbour:node.second)
        {
          cout << "{" << neighbour.first << ", " << neighbour.second << "}" << ", ";
        }

      cout << endl;
    }
}
};

int main() {

  Graph g;
  g.addEdge(1, 0, 2, 1);
  g.addEdge(0, 2, 6, 1);
  g.addEdge(3, 4, 9, 1);
  g.addEdge(3, 2, 7, 1);
  
  g.printAdjList();
}
