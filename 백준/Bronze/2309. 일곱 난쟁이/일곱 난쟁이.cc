#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int x;
    int sum = 0;
    vector<int> A;
    for(int i = 0; i < 9; i++){
        cin >> x;
        A.push_back(x);
        sum += x;
    } // 입력받으면서 합산

    sort(A.begin(), A.end()); // 정렬

    bool found = false;
    for(int i = 0; i < 8 && !found; i++){ // 일찍 종료할 수 있도록 제어
        for(int j = i + 1; j < 9; j++){
            if(sum - A[i] - A[j] == 100){
                A.erase(A.begin() + j); // 두 번째 요소를 먼저 제거
                A.erase(A.begin() + i); // 그다음 첫 번째 요소를 제거
                found = true; // 정답을 찾았으므로 반복문 종료 신호
                break;
            }
        }
    }

    for(int k = 0; k < A.size(); k++)
        cout << A[k] << endl;
}
