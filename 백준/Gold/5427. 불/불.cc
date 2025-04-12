#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {0, 0, 1, -1}; // 동서남북
int dy[4] = {1, -1, 0, 0};

int w, h;
vector<string> board;
vector<vector<int>> fire_dist;
vector<vector<int>> sang_dist;
queue<pair<int, int>> fireQ;
queue<pair<int, int>> sangQ;

void bfs_fire() {
    while (!fireQ.empty()) {
        auto [x, y] = fireQ.front(); fireQ.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (board[nx][ny] == '#' || fire_dist[nx][ny] != -1) continue;
            fire_dist[nx][ny] = fire_dist[x][y] + 1;
            fireQ.push({nx, ny});
        }
    }
}

int bfs_sang() {
    while (!sangQ.empty()) {
        auto [x, y] = sangQ.front(); sangQ.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
                return sang_dist[x][y] + 1; // 탈출!
            }
            if (board[nx][ny] == '#' || sang_dist[nx][ny] != -1) continue;
            if (fire_dist[nx][ny] != -1 && fire_dist[nx][ny] <= sang_dist[x][y] + 1) continue;
            sang_dist[nx][ny] = sang_dist[x][y] + 1;
            sangQ.push({nx, ny});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> w >> h;
        board = vector<string>(h);
        fire_dist = vector<vector<int>>(h, vector<int>(w, -1));
        sang_dist = vector<vector<int>>(h, vector<int>(w, -1));
        while (!fireQ.empty()) fireQ.pop();
        while (!sangQ.empty()) sangQ.pop();

        for (int i = 0; i < h; i++) {
            cin >> board[i];
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '*') {
                    fireQ.push({i, j});
                    fire_dist[i][j] = 0;
                } else if (board[i][j] == '@') {
                    sangQ.push({i, j});
                    sang_dist[i][j] = 0;
                }
            }
        }

        bfs_fire();
        int res = bfs_sang();
        if (res == -1) cout << "IMPOSSIBLE\n";
        else cout << res << "\n";
    }
}
