#include <vector>
#include <array>
#include <algorithm>

constexpr std::array<std::pair<int, int>, 4> adj4 {{
  {0, 1}, {1, 0}, {0, -1}, {-1, 0}
}};

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
  int n = snail_map[0].size(), dir = 0, x = 0, y = 0;
  std::vector<int> ret;
  if(!n) return ret;
  std::vector<std::vector<bool>> vis(n, std::vector<bool>(n, false));
  while(true) {
    ret.push_back(snail_map[x][y]);
    vis[x][y] = true;
    if((int)ret.size() >= n * n) break;
    int nx = x + adj4[dir].first, ny = y + adj4[dir].second;
    if(nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny]) {  // turn
      dir = (dir + 1) % 4;
      nx = x + adj4[dir].first, ny = y + adj4[dir].second;
    }
    x = nx, y = ny;
  }
  return ret;
}