#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};       // 아래, 오른쪽, 위, 왼쪽
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int i;

int bfs(int x, int y, int a, int b, vector<vector<int>>& board) {
    vector<vector<int>> dist(i, vector<int>(i, -1));
    queue<pair<int,int>> Q;
    Q.push({x, y});
    dist[x][y] = 0;

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            // ⛔ 범위 먼저 검사!
            if (nx < 0 || nx >= i || ny < 0 || ny >= i) continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;

            if (nx == a && ny == b) return dist[nx][ny];

            Q.push({nx, ny});
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    while(n--){
        
        cin>>i;
        vector<vector<int>> board(i, vector<int>(i, 0));
        vector<vector<int>> vis(i, vector<int>(i, 0));

        int x, y;
        int num=0;
        cin>>x>>y;
        board[x][y]=1;
        int a, b;
        cin>>a>>b;
        board[a][b]=2;
        if(x==a && y==b){
            cout<<0<<"\n";
        }
        else{
            cout<<bfs(x, y, a, b, board)<<"\n";
        }
        
    }

    return 0;
}

