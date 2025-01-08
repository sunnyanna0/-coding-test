#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<int> v;
    int erased=0;
//     for (int i = 0; i < number.size(); i++) {
//         int current = stoi(string(1, number[i])); // 현재 숫자

//         // 스택의 마지막 숫자와 비교
//         while (!v.empty() && erased < k && v.back() < current) {
//             v.pop_back(); // 이전 숫자를 제거
//             erased++;     // 제거 카운트 증가
//         }

//         v.push_back(current); // 현재 숫자를 추가
//     }
    for (char digit : number) {
        // 스택처럼 동작
        while (!answer.empty() && erased < k && answer.back() < digit) {
            answer.pop_back(); // 이전 숫자를 제거
            erased++;          // 제거 카운트 증가
        }
        answer.push_back(digit); // 현재 숫자를 추가
    }
    while (erased < k) {
        answer.pop_back();
        erased++;
    }
    
    for(int i=0 ; i<v.size() ; i++){
        answer.append(to_string(v[i]));
    }
    
    
    return answer;
}