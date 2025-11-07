#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0 ; i<scoville.size() ; i++){
        pq.push(scoville[i]);
    }
    // priority_queue<int> temp = pq; // 복사본
    // while (!temp.empty()) {
    //     cout << temp.top() << " ";
    //     temp.pop();
    // }
    // cout << endl;
    while(pq.size() > 1 && pq.top() < K){
        
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        
        int mixed = first + second * 2;
        pq.push(mixed);
        answer++;

    }
    if (pq.top()>=K){
        return answer;
    }
    else return -1;
}