#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end()); //처음에 sort안함

    vector<int> actual_lost;
    for (auto it = lost.begin(); it != lost.end(); ) {
        auto found = find(reserve.begin(), reserve.end(), *it);
        if (found != reserve.end()) {
            reserve.erase(found); // 여벌 체육복 제거
            it = lost.erase(it); // lost에서도 제거
        } else {
            ++it;
        }
    }

    int answer = n - lost.size();  // 초기 체육복을 가진 학생 수
    for (int i = 0; i < lost.size(); ++i) {
        auto found = find(reserve.begin(), reserve.end(), lost[i] - 1);
        if (found != reserve.end()) {
            reserve.erase(found);
            answer++;
        } else {
            found = find(reserve.begin(), reserve.end(), lost[i] + 1);
            if (found != reserve.end()) {
                reserve.erase(found);
                answer++;
            }
        }
    }
    
    return answer;
}