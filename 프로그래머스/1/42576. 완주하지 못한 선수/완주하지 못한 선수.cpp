#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    // 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    // 순차 비교
    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i]) {
            return participant[i];
        }
    }
    
    // 마지막 사람이 완주하지 못한 경우
    return participant.back();
}
