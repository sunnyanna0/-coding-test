#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 사용자 정의 비교 함수
bool customCompare(int a, int b) {
    // 두 숫자를 문자열로 변환하고 이어붙인 결과를 비교
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string solution(vector<int> numbers) {
    // 사용자 정의 비교 함수로 정렬
    sort(numbers.begin(), numbers.end(), customCompare);

    // 결과 문자열 생성
    string answer = "";
    for (int num : numbers) {
        answer += to_string(num);
    }

    // 모든 숫자가 0인 경우 처리
    if (answer[0] == '0') {
        return "0";
    }

    return answer;
}
