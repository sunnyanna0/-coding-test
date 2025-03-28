#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count_bluray(const vector<int>& v, int size) {
    int count = 1;
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (sum + v[i] > size) {
            count++;
            sum = v[i];
        } else {
            sum += v[i];
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    int max_v = 0, total = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        max_v = max(max_v, v[i]);
        total += v[i];
    }

    int left = max_v;
    int right = total;
    int answer = total;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = count_bluray(v, mid);
        if (cnt <= m) {
            answer = mid;     // 가능하니까 저장하고 더 줄여보기
            right = mid - 1;
        } else {
            left = mid + 1;   // 너무 작아서 m개로 안 나눠짐 → 늘려야 함
        }
    }

    cout << answer << '\n';
    return 0;
}
