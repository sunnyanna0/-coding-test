#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool is_prime(int n){
    int sum=0;
    for(int i=1 ; i<=n ; i++){
        if(n%i==0){
            sum++;
        }
    }
    if(sum==2){
        return true;
    }
    else return false;
}

int solution(string numbers) {
    int answer = 0;
    set<int> unique_numbers;
    
    // 모든 길이에 대해 순열 생성
    for (int len = 1; len <= numbers.size(); len++) {
        string temp = numbers;
        sort(temp.begin(), temp.end()); // 순열을 생성하기 위해 정렬

        do {
            string num_str = temp.substr(0, len); // 길이가 len인 부분 문자열
            unique_numbers.insert(stoi(num_str)); // 문자열을 정수로 변환하여 삽입
        } while (next_permutation(temp.begin(), temp.end())); // 다음 순열 생성
    }
    for(int it:unique_numbers){
        if(is_prime(it)){
            answer++;
        }
    }
    return answer;
}