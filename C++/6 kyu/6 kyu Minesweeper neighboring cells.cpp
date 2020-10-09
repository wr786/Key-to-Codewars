#include <algorithm>
#include <array>
using namespace std;

constexpr array<pair<int, int>, 8> adj_8 {{
  {-1, -1}, {-1, 0}, {-1, 1},
  {0, -1},           {0, 1},
  {1, -1},   {1, 0}, {1, 1}
}};

inline bool check_boundary(int x, int y, int rows, int cols) {
  return 0 <= x && x < rows && 0 <= y && y < cols;
}

void compute_number_mines(char **board, const int rows, const int cols) {
  for(int i=0; i<rows; i++)
    for(int j=0; j<cols; j++) {
      if(board[i][j] == 'R') {
        int cnt = 0;
        for(auto& dir: adj_8) {
          int nx = i + dir.first;
          int ny = j + dir.second;
          if(!check_boundary(nx, ny, rows, cols)) continue;
          if(board[nx][ny] == 'o') cnt++;
        }
        board[i][j] = cnt + '0';
      } 
    }
}