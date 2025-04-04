#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long s;
    cin >> s;
    long long answer = 0;

    long long left = 1, right = s;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = mid * (mid + 1) / 2;

        if (sum <= s) {
            answer = mid;       // 조건 만족 → 정답 후보
            left = mid + 1;     // 더 큰 N을 시도
        } else {
            right = mid - 1;    // 너무 커서 실패 → 줄이기
        }
    }

    cout << answer << "\n";
    return 0;
}
