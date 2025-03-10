#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string p, arr;
        int n;
        cin >> p >> n >> arr;

        vector<int> v;
        string num = "";

        // 입력 배열을 숫자로 변환하여 vector<int>에 저장
        for (char c : arr) {
            if (isdigit(c)) {
                num += c;
            } else if (!num.empty()) {
                v.push_back(stoi(num));
                num = "";
            }
        }

        bool rev = false;  // 뒤집힘 여부
        int start = 0, end = v.size(); // 실제 데이터 조작을 위한 인덱스
        bool error = false;

        // 명령어 처리
        for (char cmd : p) {
            if (cmd == 'R') {
                rev = !rev;
            } else { // 'D'
                if (start == end) { // 배열이 비어있는 경우
                    error = true;
                    break;
                }
                if (!rev) start++;  // 정방향이면 앞에서 삭제
                else end--;         // 뒤집힌 상태면 뒤에서 삭제
            }
        }

        // 출력
        if (error) {
            cout << "error\n";
        } else {
            cout << "[";
            if (start < end) {
                if (rev) { // 뒤집힌 상태면 거꾸로 출력
                    for (int i = end - 1; i >= start; i--) {
                        cout << v[i];
                        if (i > start) cout << ",";
                    }
                } else { // 정방향 출력
                    for (int i = start; i < end; i++) {
                        cout << v[i];
                        if (i < end - 1) cout << ",";
                    }
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}
