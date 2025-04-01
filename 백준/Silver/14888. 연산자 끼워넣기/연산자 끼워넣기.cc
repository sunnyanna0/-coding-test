#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v_digit;
int op[4]; // +, -, *, /
int max_result = -1e9;
int min_result = 1e9;

void dfs(int idx, int current) {
    if (idx == n) {
        max_result = max(max_result, current);
        min_result = min(min_result, current);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;

            if (i == 0) dfs(idx + 1, current + v_digit[idx]);
            else if (i == 1) dfs(idx + 1, current - v_digit[idx]);
            else if (i == 2) dfs(idx + 1, current * v_digit[idx]);
            else if (i == 3) dfs(idx + 1, current / v_digit[idx]); // 음수 나눗셈 조심

            op[i]++; // 백트래킹
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    v_digit.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v_digit[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i]; // 연산자 개수 입력
    }

    dfs(1, v_digit[0]);

    cout << max_result << '\n' << min_result << '\n';

    return 0;
}
