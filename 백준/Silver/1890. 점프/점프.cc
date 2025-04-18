#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<long long>> board(n, vector<long long>(n));
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    dp[0][0] = 1;  // 시작점

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == 0 || board[i][j] == 0) continue;  // 갈 수 없는 곳이거나 끝
            int jump = board[i][j];
            if (i + jump < n) dp[i + jump][j] += dp[i][j];  // 아래로
            if (j + jump < n) dp[i][j + jump] += dp[i][j];  // 오른쪽으로
        }
    }

    cout << dp[n - 1][n - 1] << '\n';  // 도착점에 도달하는 경우의 수 출력
}
