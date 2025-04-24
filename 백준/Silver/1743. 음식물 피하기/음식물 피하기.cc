#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int x, int y, vector<vector<int>>& board, vector<vector<int>>& vis, int n, int m){
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y]=1;
    int size=1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny]==0) continue;
            vis[nx][ny]=1;
            Q.push({nx, ny});
            size++;
        }
        
    }
    return size;
}

int main(){
    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    while(k--){
        int r, c;
        cin>>r>>c;
        board[r-1][c-1]=1; //인덱스 보정 까먹지 말기!
        
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && vis[i][j] == 0) {
                result = max(result, bfs(i, j, board, vis, n, m));
            }
        }
    }
    cout << result << '\n';
    
}