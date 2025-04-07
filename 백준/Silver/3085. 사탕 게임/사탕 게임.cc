#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int checkMax(const vector<vector<char>>& board, int n) {
    int maxCount = 1;
    for (int i = 0; i < n; i++) {
        // 가로 검사
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (board[i][j] == board[i][j - 1]) cnt++;
            else cnt = 1;
            maxCount = max(maxCount, cnt);
        }

        // 세로 검사
        cnt = 1;
        for (int j = 1; j < n; j++) {
            if (board[j][i] == board[j - 1][i]) cnt++;
            else cnt = 1;
            maxCount = max(maxCount, cnt);
        }
    }
    return maxCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 오른쪽과 교환
            if (j + 1 < n && board[i][j] != board[i][j + 1]) {
                swap(board[i][j], board[i][j + 1]);
                answer = max(answer, checkMax(board, n));
                swap(board[i][j], board[i][j + 1]);
            }

            // 아래와 교환
            if (i + 1 < n && board[i][j] != board[i + 1][j]) {
                swap(board[i][j], board[i + 1][j]);
                answer = max(answer, checkMax(board, n));
                swap(board[i][j], board[i + 1][j]);
            }
        }
    }

    cout << answer;

    return 0;
}
