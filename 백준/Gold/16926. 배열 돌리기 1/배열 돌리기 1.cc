#include <iostream>
#include <vector>
using namespace std;

int n, m, R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> R;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int layers = min(n, m) / 2;

    for (int layer = 0; layer < layers; layer++) {
        // 레이어마다 돌려야 할 길이 계산
        int h = n - 2 * layer;
        int w = m - 2 * layer;
        int len = 2 * (h + w) - 4;
        int rot = R % len;

        for (int r = 0; r < rot; r++) {
            int temp = a[layer][layer];

            // 좌 ←
            for (int j = layer; j < m - 1 - layer; j++)
                a[layer][j] = a[layer][j + 1];

            // 상 ↑
            for (int i = layer; i < n - 1 - layer; i++)
                a[i][m - 1 - layer] = a[i + 1][m - 1 - layer];

            // 우 →
            for (int j = m - 1 - layer; j > layer; j--)
                a[n - 1 - layer][j] = a[n - 1 - layer][j - 1];

            // 하 ↓
            for (int i = n - 1 - layer; i > layer + 1; i--)
                a[i][layer] = a[i - 1][layer];

            a[layer + 1][layer] = temp;
        }
    }

    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }

    return 0;
}
