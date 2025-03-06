#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v;

    // 1부터 n까지 벡터 초기화
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    int m, count = 0;
    cin >> m;

    while (m > 0) {
        int x;
        cin >> x;

        // x가 위치한 인덱스를 찾음
        int idx = 0;
        while (v[idx] != x) idx++;

        // 왼쪽으로 회전 (앞으로 땡기기)
        if (idx <= v.size() - idx) {
            while (idx--) {
                v.push_back(v[0]);  // 첫 번째 요소를 뒤로 보냄
                v.erase(v.begin()); // 첫 번째 요소 삭제
                count++;
            }
        }
        // 오른쪽으로 회전 (뒤에서 앞으로 당기기)
        else {
            int move_right = v.size() - idx;  // 오른쪽 이동 횟수
            while (move_right--) {
                v.insert(v.begin(), v.back());  // 마지막 요소를 앞으로 보냄
                v.pop_back();  // 마지막 요소 삭제
                count++;
            }
        }

        // 맨 앞의 x 제거
        v.erase(v.begin());
        m--;
    }

    cout << count;
    return 0;
}
