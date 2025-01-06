#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // min, max

using namespace std;

int solution(string name) {
    int answer = 0;
    int size = name.size();

    // 알파벳 변경 비용 계산
    for (int i = 0; i < size; ++i) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
    }

    // 커서 이동 비용 계산
    int move = size - 1; // 기본적으로 오른쪽으로 끝까지 이동
    for (int i = 0; i < size; ++i) {
        int next = i + 1;
        while (next < size && name[next] == 'A') {
            ++next;
        }
        // 오른쪽으로 이동 + 왼쪽으로 돌아가기
        move = min(move, i + size - next + min(i, size - next));
    }

    answer += move; // 최적의 이동 비용 추가
    return answer;
}
