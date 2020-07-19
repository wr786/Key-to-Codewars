#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

constexpr array<pair<int, int>, 4> adj4 {{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} }};

void dfs(int x, int y, const vector<vector<int>>& maze, vector<vector<bool>>& vis) {
  vis[x][y] = true;
  for(auto& dir: adj4) {
    int nx = x + dir.first, ny = y + dir.second;
    if(0 <= nx && nx < (int)maze.size() && 0 <= ny && ny < (int)maze.size() && !vis[nx][ny] && maze[nx][ny] != 'W') {
      dfs(nx, ny, maze, vis);
    }
  }
}

bool path_finder(string maze) {
  int n = (sqrt(4 * maze.length() + 5) - 1) / 2;  // the size of the maze
  vector<vector<int>> Maze(n, vector<int>(n, 0));
  vector<vector<bool>> vis(n, vector<bool>(n, false));
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      Maze[i][j] = maze[j + i*(n+1)];
  dfs(0, 0, Maze, vis);
  return vis[n-1][n-1];
}