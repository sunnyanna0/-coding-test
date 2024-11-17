#include <iostream>
#include <cmath>
using namespace std;

// 소수 판별 함수
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void dfs(int current, int depth, int N) {
    if (depth == N) { // N자리 숫자 완성
        cout << current << endl;
        return;
    }
    for (int i = 1; i <= 9; i++) { // 다음 자리수 추가
        int next = current * 10 + i; // 현재 숫자에 i 추가
        if (isPrime(next)) { // 소수인 경우만 탐색 진행
            dfs(next, depth + 1, N);
        }
    }
}

int main() {
    int N;
    cin >> N;

    // 한 자리 소수부터 시작
    dfs(2, 1, N);
    dfs(3, 1, N);
    dfs(5, 1, N);
    dfs(7, 1, N);

    return 0;
}
