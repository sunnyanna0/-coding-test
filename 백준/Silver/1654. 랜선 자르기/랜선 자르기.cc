#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    long long max_len = 0;
    for (int i = 0; i < k; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
        max_len = max(max_len, x);
    }

    long long low = 1;
    long long high = max_len;
    long long answer = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

        long long cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += v[i] / mid;
        }

        if (cnt >= n) {
            answer = mid;         // 더 길게 자를 수 있나 확인
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
