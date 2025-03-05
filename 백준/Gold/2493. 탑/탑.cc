#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // 입출력 속도 최적화

    int n;
    cin >> n;

    stack<pair<int, int>> s;  // (탑의 높이, 탑의 인덱스)

    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;

        // 현재 탑보다 낮은 탑들은 pop
        while (!s.empty() && s.top().first < height) {
            s.pop();
        }

        // 스택이 비어 있으면 0 출력, 그렇지 않으면 가장 가까운 높은 탑의 인덱스 출력
        if (s.empty()) {
            cout << "0 ";
        } else {
            cout << s.top().second << " ";
        }

        // 현재 탑을 스택에 push
        s.push({height, i});
    }

    return 0;
}
