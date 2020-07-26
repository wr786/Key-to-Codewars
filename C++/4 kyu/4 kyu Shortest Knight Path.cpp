#include <string>
#include <queue>
#include <array>
#include <algorithm>
#include <cstring>
bool vis[8][8];
std::array<std::pair<int, int>, 8> adj8 {{
            {-2, -1}, {-2, 1}, 
    {-1, -2},                 {-1, 2},
    { 1, -2},                 { 1, 2},
            { 2, -1}, { 2, 1}
}};

struct Node {
  std::pair<int, int> pos;
  int steps;
  Node(std::pair<int, int> p, int s=0): pos(p), steps(s) {}
  bool operator < (const Node& other) const {return other.steps < steps;}
};

inline bool check_boundary(int x, int y) {
  return (0 <= x) && (x < 8) && (0 <= y) && (y < 8);
}

int knight(std::string start, std::string finish) {
  memset(vis, false, sizeof(vis));
  std::pair<int, int> target = {finish[0]-'a', finish[1]-'0'-1};
  std::pair<int, int> fromPos = {start[0]-'a', start[1]-'0'-1};
  vis[fromPos.first][fromPos.second] = true;
  Node from(fromPos);
  std::priority_queue<Node> pq;  pq.push(from);
  while(!pq.empty()) {
    Node cur = pq.top(); pq.pop();
    if(cur.pos == target) {
      return cur.steps;
    }
    for(auto dir: adj8) {
      int nx = cur.pos.first + dir.first, ny = cur.pos.second + dir.second;
      if(check_boundary(nx, ny) && !vis[nx][ny]) {
        vis[nx][ny] = true;
        pq.push(Node({nx, ny}, cur.steps+1));
      }
    }
  }
  return -1;  // error
}