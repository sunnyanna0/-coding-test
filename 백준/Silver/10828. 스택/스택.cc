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

    for(int i=0 ; i<N ; i++){
        string str;
        cin >> str;

        if(str=="push"){
            int x;
            cin >> x;
            A.push_back(x);
        }
        else if(str=="pop"){
            if(!A.empty()) {
                cout << A.back() << endl;
                A.pop_back();
            } else {
                cout << -1 << endl;  // 벡터가 비어 있을 때 처리
            }
        }
        else if(str=="size"){
            cout << A.size() <<endl;
        }
        else if(str=="empty"){
            cout << A.empty() <<endl;
        }
        else if(str=="top"){
            if(!A.empty()) {
                cout << A.back() << endl;
            } else {
                cout << -1 << endl;  // 벡터가 비어 있을 때 처리
            }
        }
    }

}