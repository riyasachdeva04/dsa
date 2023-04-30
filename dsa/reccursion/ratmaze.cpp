// rat in a maze
#include <iostream>
using namespace std;
#include<vector>

bool isSafe(int maze[][4], vector <vector<int>> visited, int i, int j, int rows, int cols)
{
    if((i>=0 && i<rows) && (j>=0 && j<cols) && (visited[i][j] == false) && (maze[i]  [j] ==1))
    {
      return true;
    }

    return false;
}

bool solve(int maze[][4], vector <vector<int>> visited, int rows, int cols, int i, int j, string ans, vector<string>& output)
{
    if(i == rows-1 && j == cols-1)
      {output.push_back(ans);
      return true;}

    if(maze[i][j] == 1)
      {
        if(isSafe(maze, visited, i+1, j, rows, cols))
        {
          visited[i+1][j] = true;
          solve(maze, visited, rows, cols, i+1, j, ans + 'D', output);
          visited[i+1][j] = false;
        }
        

        if(isSafe(maze, visited, i, j-1, rows, cols))
        {
          visited[i][j-1] = true;
          solve(maze, visited, rows, cols, i, j-1, ans + 'L', output);
          visited[i][j-1] = false;
        }
        

        if(isSafe(maze, visited, i, j+1, rows, cols))
        {
          visited[i][j+1] = true;
          solve(maze, visited, rows, cols, i, j+1, ans + 'R', output);
          visited[i][j+1] = false;
        }
        

        if(isSafe(maze, visited, i-1, j, rows, cols))
        {
          visited[i-1][j] = true;
          solve(maze, visited, rows, cols, i-1, j, ans + 'U', output);
          visited[i-1][j] = false;
        }
        





      }
    
    
  return false;
}

int main() {
  int rows = 4;
  int cols = 4;

int maze[4][4] = { {1,0,0,0}, 
                 {1,1,0, 1},
                 {1,1,0,0},
                 {0,1,1,1}};

string ans = "";
vector<string> output;

vector <vector<int>> visited(rows, vector<int>(cols, false));

solve(maze, visited, rows, cols, 0, 0, ans, output);


if(maze[0][0] == 0 || maze[rows-1][cols-1] == 0)
  cout << "No path available";

for(auto i: output)
{
  cout << i << " ";
}

}