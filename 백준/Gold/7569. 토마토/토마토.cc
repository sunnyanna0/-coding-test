#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void bfs(vector<vector<vector<int>>>& board, int m, int n, int h) {
    queue<tuple<int, int, int>> Q;

    // 익은 토마토들을 모두 큐에 추가 (multi-source BFS)
    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (board[z][y][x] == 1) {
                    Q.push({x, y, z});
                }
            }
        }
    }

    // BFS 실행
    while (!Q.empty()) {
        auto [x, y, z] = Q.front(); Q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h) continue;
            if (board[nz][ny][nx] != 0) continue;
            board[nz][ny][nx] = board[z][y][x] + 1;
            Q.push({nx, ny, nz});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n, h;
    cin >> m >> n >> h;

    vector<vector<vector<int>>> board(h, vector<vector<int>>(n, vector<int>(m)));

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cin >> board[z][y][x];
            }
        }
    }

    bfs(board, m, n, h);

    int answer = 0;
    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (board[z][y][x] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                answer = max(answer, board[z][y][x]);
            }
        }
    }

    cout << answer - 1 << '\n';
    return 0;
}
