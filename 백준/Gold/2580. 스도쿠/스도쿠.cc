#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[9][9]; // 스도쿠 보드

// 가능한 숫자를 확인하는 함수
vector<int> getCandidates(int x, int y) {
    vector<bool> used(10, false); // 1~9 숫자의 사용 여부를 체크

    // 가로줄 확인
    for (int i = 0; i < 9; i++) {
        if (a[x][i] != 0) {
            used[a[x][i]] = true;
        }
    }

    // 세로줄 확인
    for (int i = 0; i < 9; i++) {
        if (a[i][y] != 0) {
            used[a[i][y]] = true;
        }
    }

    // 3x3 박스 확인
    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;
    for (int i = startX; i < startX + 3; i++) {
        for (int j = startY; j < startY + 3; j++) {
            if (a[i][j] != 0) {
                used[a[i][j]] = true;
            }
        }
    }

    // 후보 숫자 추출
    vector<int> candidates;
    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            candidates.push_back(i);
        }
    }
    return candidates;
}

// 백트래킹 함수
bool solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] == 0) { // 빈칸 찾기
                vector<int> candidates = getCandidates(i, j);
                for (int num : candidates) {
                    a[i][j] = num; // 후보 숫자 대입
                    if (solve()) { // 재귀 호출로 다음 빈칸 풀기
                        return true;
                    }
                    a[i][j] = 0; // 실패 시 원상복구
                }
                return false; // 모든 후보가 실패하면 현재 경로는 잘못됨
            }
        }
    }
    return true; // 모든 빈칸을 채운 경우
}

int main() {
    // 스도쿠 입력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
        }
    }

    // 스도쿠 풀이
    if (solve()) {
        // 정답 출력
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
