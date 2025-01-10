#include <iostream>
using namespace std;

int main(void) {
    int n, x;
    cin >> n;

    int arr[1000001] = {}; // 1 ≤ ai ≤ 1,000,000 조건에 맞는 배열 선언

    // 배열 입력 처리
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[a]++; // 해당 값 존재 여부 및 빈도 저장
    }

    cin >> x;

    int answer = 0;

    // 두 수의 합 검사
    for (int i = 1; i <= x / 2; i++) {
        if (x - i <= 1000000 && arr[i] > 0 && arr[x - i] > 0) {
            if (i == x - i) { // 같은 값으로 쌍을 이루는 경우
                //answer += arr[i] / 2; // 쌍의 개수 추가
            } else {
                answer += min(arr[i], arr[x - i]); // 가능한 최소 쌍 추가
            }
            arr[i] = 0;       // 중복 방지
            arr[x - i] = 0;   // 중복 방지
        }
    }

    cout << answer; // 결과 출력
    return 0;
}
