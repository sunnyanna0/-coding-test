#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main(){
    int answer=0;
    int n;
    cin>>n;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }

    sort(v.begin(), v.end()); // 사전순 정렬
    for (int i = 0; i < n; i++) {
        bool isPrefix = false;
        for (int j = i + 1; j < n; j++) { 
            if (v[j].substr(0, v[i].size()) == v[i]) {
                isPrefix = true;
                break; // 접두사가 발견되면 i번 단어는 제외
            }
        }
        if (!isPrefix) answer++; // 접두사 아니면 answer++
    }
    cout<<answer;
}