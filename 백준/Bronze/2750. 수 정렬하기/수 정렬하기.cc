#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A;
    int x;

    for(int i=0 ; i<N ; i++){
        cin >> x;
        bool exists = false;
        for(int j = 0; j < A.size(); j++){
            if(x == A[j]){
                exists = true;
                break;  // 중복된 값을 찾으면 더 이상 비교하지 않고 루프 탈출
            }
        }
        if(!exists){
            A.push_back(x);
        }
        
    }

    sort(A.begin(), A.end());

    for(int i=0 ; i<A.size() ; i++){
        cout << A[i] << endl;
    }
}