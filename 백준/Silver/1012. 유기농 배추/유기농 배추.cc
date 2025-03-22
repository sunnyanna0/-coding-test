#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};       // 아래, 오른쪽, 위, 왼쪽
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y, vector<vector<int>>& board, vector<vector<bool>>& vis, int m, int n) {
    queue<pair<int,int>> Q;
    Q.push({x, y});
    vis[x][y] = true;

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            // 세로 m, 가로 n
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || board[nx][ny] == 0) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int m, n, k;  // m: 세로, n: 가로, k: 배추 개수
        cin >> n >> m >> k;

        vector<vector<int>> board(m, vector<int>(n, 0));
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;  // (x, y) 좌표에 배추가 있음
        }

        int answer = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1 && !vis[i][j]) {
                    bfs(i, j, board, vis, m, n);
                    answer++;
                }
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
