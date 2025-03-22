#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// int board[502][502];   // 지도 (0: 빈칸, 1: 배추)
// int vis[502][502]={0};  

int dx[4] = {1, 0, -1, 0};       // 아래, 오른쪽, 위, 왼쪽
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y, vector<vector<int>>& board, vector<vector<int>>& vis, int m, int n) {
    queue<pair<int,int>> Q;
    Q.push({x, y});
    vis[x][y] = 1;
    int biggest=0;
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        biggest++;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            // 세로 m, 가로 n
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || board[nx][ny] == 0) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    return biggest;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, m;
    cin>>m>>n;
    vector<vector<int>> board(m, vector<int>(n, 0));
    vector<vector<int>> vis(m, vector<int>(n, 0));
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            int x;
            cin>>x;
            board[i][j]=x;
        }
    }
    int answer_count=0;
    int biggest=0;
    int answer_biggest=0;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(board[i][j]==1 && vis[i][j]!=1){
                biggest=0;
                biggest=bfs(i, j, board, vis, m, n);
                answer_count++;
                if(answer_biggest<biggest){
                    answer_biggest=biggest;
                }
            }
        }
    }

    cout<<answer_count<<"\n"<<answer_biggest;

    return 0;
}
