#include <iostream>
#include <vector>
#include <queue> // 잊지말자!!! 컴파일 에러 난다!!!
#include <algorithm>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int m, int n, vector<vector<int>>& board, vector<vector<int>>& vis, int x, int y){ //넓이를 반환
    int area=0;
    
    queue<pair<int,int>> Q;
    Q.push({x, y});
    vis[x][y] = 1;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        area++;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            // 세로 m, 가로 n
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || board[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }

    return area;
}

int main(){
    int m,n,k;
    cin>>m>>n>>k;
    vector<vector<int>> board(m, vector<int>(n, 0));
    vector<vector<int>> vis(m, vector<int>(n, 0));

    while(k--){
        int left_x, left_y, right_x, right_y;
        cin>>left_x>>left_y>>right_x>>right_y;
        for(int y=left_y ; y<right_y ; y++){
            for(int x=left_x ; x<right_x ; x++){
                board[y][x]=1;
            }
        }

    }

    vector<int> v; //각각 직사각형의 넓이들 저장

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(board[i][j]==1 || vis[i][j]){
                continue;
            }
            else{
                v.push_back(bfs(m, n, board, vis ,i, j));
            }
        }
    }

    cout<<v.size()<<"\n";
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
}