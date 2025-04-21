#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int dx[4] = {1, 0, -1, 0};  // 아래, 오른쪽, 위, 왼쪽
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& vis, int n, int m, char team) {
    queue<pair<int,int>> Q;
    int count = 1;
    Q.push({x, y});
    vis[x][y] = true;

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny]) continue;
            if (board[nx][ny] == team) {
                vis[nx][ny] = true;
                Q.push({nx, ny});
                count++;
            }
        }
    }

    return count * count;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> board(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int sum_w = 0, sum_b = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                if (board[i][j] == 'W')
                    sum_w += bfs(i, j, board, vis, n, m, 'W');
                else if (board[i][j] == 'B')
                    sum_b += bfs(i, j, board, vis, n, m, 'B');
            }
        }
    }

    cout << sum_w << " " << sum_b << endl;
    return 0;
}
