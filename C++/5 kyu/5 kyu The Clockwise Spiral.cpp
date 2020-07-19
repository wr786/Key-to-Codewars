#include <vector>
#include <array>
#include <algorithm>

constexpr std::array<std::pair<int, int>, 4> adj4 {{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} }};

std::vector<std::vector<int>> create_spiral(int n)
{
    if(n < 1) return {};
    std::vector<std::vector<int>> ret(n, std::vector<int>(n, 0));
    int dir = 0, cnt = 1, x = 0, y = 0;
    while(true) {
        ret[x][y] = cnt++;
        if(cnt > n*n) return ret;
        int nx = x + adj4[dir].first, ny = y + adj4[dir].second;
        if(nx < 0 || ny < 0 || nx >= n || ny >= n || ret[nx][ny]) {
            dir = (dir + 1) % 4;  // turn
            nx = x + adj4[dir].first, ny = y + adj4[dir].second;
        }
        x = nx, y = ny;
    }
}