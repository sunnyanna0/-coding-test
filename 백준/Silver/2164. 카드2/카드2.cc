#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0); //입출력 속도 향상
    cin.tie(NULL);  // 🚀 입력 속도 향상
    cout.tie(NULL); // 🚀 출력 속도 향상 (필수는 아님)

    int n;
    cin>>n;
    queue<int> q;

    for(int i=1 ; i<=n ; i++){
        q.push(i);
    }
    while(q.size()>1){
        q.pop();
        int x=q.front();
        q.pop();
        q.push(x);
    }
    cout<<q.front();
    return 0;
}
