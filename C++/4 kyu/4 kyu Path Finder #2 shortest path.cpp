#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

constexpr array<pair<int, int>, 4> adj4 {{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} }};
int ans, n;

void dfs(int x, int y, const vector<vector<int>>& maze, vector<vector<int>>& vis, int steps) {
  if(x == n-1 && y == n-1) {
    if(ans == -1) ans = steps;
    else ans = min(ans, steps);
  }
  if(ans != -1 && steps >= ans) return;  // prune
  vis[x][y] = steps;  // another prune
  for(auto& dir: adj4) {
    int nx = x + dir.first, ny = y + dir.second;
    if(0 <= nx && nx < n && 0 <= ny && ny < n && vis[nx][ny] > steps+1 && maze[nx][ny] != 'W') {
      dfs(nx, ny, maze, vis, steps + 1);
    }
  }
}

int path_finder(string maze) {
  n = (sqrt(4 * maze.length() + 5) - 1) / 2;  // the size of the maze
  vector<vector<int>> Maze(n, vector<int>(n, 0));
  vector<vector<int>> vis(n, vector<int>(n, 0x3f3f3f3f));
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      Maze[i][j] = maze[j + i*(n+1)];
  ans = -1;
  dfs(0, 0, Maze, vis, 0);
  return ans;
}