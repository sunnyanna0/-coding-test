// dist는 거리 저장 + 최소 거리 계산 둘 다 할 수 있는 핵심 구조!!!!



#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int dx[4] = {1, 0, -1, 0};       // 아래, 오른쪽, 위, 왼쪽
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y, vector<vector<int>>& board, vector<vector<int>>& vis, int n, int m, int sum){
    queue<pair<int, int>> Q;
    Q.push({x, y});

    vector<vector<int>> dist(n, vector<int>(m, 0));
    dist[0][0] = 1; // 시작점은 항상 1칸

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == 0 || dist[nx][ny] > 0) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1; // 이전 칸 수 + 1
            Q.push({nx, ny});
        }
    }
    return dist[n-1][m-1];
}

int main() {
    int m, n;
    cin >> n >> m;

    int answer_min=10000;
    vector<vector<int>> board(n, vector<int>(m)); // n행 m열짜리 보드 생성
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        for(int j=0 ; j<m ; j++){
            board[i][j]=s[j]-'0';
        }
    }
    int sum=0;
    cout<<bfs(0, 0, board, vis, n, m, sum);
    
    

    return 0;
}
