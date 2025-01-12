#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void) {
    int k, n;
    cin>>k>>n;

    list<int> l;
    for(int i=1 ; i<=k ; i++){
        l.push_back(i);
    }
    auto iter=l.begin();
    cout<<"<";
    while(!l.empty()){
        // n-1만큼 이동
        for (int i = 1; i < n; i++) {
            iter++;
            if (iter == l.end()) iter = l.begin(); // 원형으로 처리
        }
        cout << *iter;
        iter = l.erase(iter);
        if (!l.empty()) {
            cout << ", ";
            if (iter == l.end()) iter = l.begin(); // 원형 처리
        }
    }
    cout<<">";
}