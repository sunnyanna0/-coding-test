#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // 가로(width)가 세로(height)보다 크거나 같은 조건으로 탐색
    for (int height = 1; height <= yellow; ++height) {
        if (yellow % height == 0) {
            int width = yellow / height;

            // (가로 + 세로) * 2 + 4 = brown 조건 확인
            if ((width + height) * 2 + 4 == brown) {
                answer.push_back(width + 2); // 가로
                answer.push_back(height + 2); // 세로
                break;
            }
        }
    }

    return answer;
}
