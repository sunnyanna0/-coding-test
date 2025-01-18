#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;       // 스택 역할을 하는 벡터
    vector<char> result; // 결과 저장 (+, -)
    int current = 1;     // 현재 push할 숫자
    bool isPossible = true;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        // 목표 숫자까지 push
        while (current <= a) {
            v.push_back(current);
            result.push_back('+');
            current++;
        }

        // 스택의 top이 목표 숫자와 같다면 pop
        if (!v.empty() && v.back() == a) {
            v.pop_back();
            result.push_back('-');
        } else {
            // 목표 숫자를 만들 수 없으면 NO 출력
            isPossible = false;
            break;
        }
    }

    // 결과 출력
    if (isPossible) {
        for (char c : result) {
            cout << c << '\n';
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
