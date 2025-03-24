#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// char board[502][502];   // 지도 (0: 빈칸, 1: 배추)
// int vis[502][502]={0};  
// int vis_rg[502][502]={0}; 

int dx[4] = {1, 0, -1, 0};       // 아래, 오른쪽, 위, 왼쪽
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y, vector<vector<char>>& board, vector<vector<int>>& vis, int m, int n) {
    queue<pair<int,int>> Q;
    Q.push({x, y});
    vis[x][y] = 1;
    char color = board[x][y];
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            // 세로 m, 가로 n
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] ) continue;
            if (board[nx][ny] != color) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

void bfs_rg(int x, int y, vector<vector<char>>& board, vector<vector<int>>& vis, int m, int n) {
    queue<pair<int,int>> Q;
    Q.push({x, y});
    vis[x][y] = 1;
    char color = board[x][y];
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            // 세로 m, 가로 n
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (vis[nx][ny]) continue;
            // R과 G는 같은 색으로 간주
            if ((color == 'R' || color == 'G') && (board[nx][ny] == 'R' || board[nx][ny] == 'G')) {
                vis[nx][ny] = 1;
                Q.push({nx, ny});
            }
            // B는 구분
            else if (board[nx][ny] == color) {
                vis[nx][ny] = 1;
                Q.push({nx, ny});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vector<char>> board(n, vector<char>(n, 0));
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<vector<int>> vis_rg(n, vector<int>(n, 0));

    int answer_normal=0;
    int answer_j=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin>>x;
            board[i][j]=x;
        }
        
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                bfs(i, j, board, vis, n, n);
                answer_normal++;
            }
            if (!vis_rg[i][j]) {
                bfs_rg(i, j, board, vis_rg, n, n);
                answer_j++;
            }
        }
    }

    cout<<answer_normal<<" "<<answer_j;
    return 0;
}
