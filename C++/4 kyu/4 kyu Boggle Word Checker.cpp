using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int n, m;
char a[151][151];
bool vis[151][151];

bool find(int x, int y, string left) {
    vis[x][y] = true;
    if(left == "") return true;
    bool ret = false;
    for(size_t dir=0; dir<8; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(nx && ny && nx <= n && ny <= m && !vis[nx][ny] && a[nx][ny] == left[0]) {
            ret |= find(nx, ny, left.substr(1));
        }
    }
    vis[x][y] = false;
    return ret;
}

bool check_word(const vector<vector<char> > &board, const string &word)
{
    n = board.size(), m = board[0].size();
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            vis[i][j] = false;
            a[i][j] = board[i-1][j-1];
        }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            if(a[i][j] == word[0]) {
                if(find(i, j, word.substr(1)))
                    return true;
            }
        }
    return false;
}