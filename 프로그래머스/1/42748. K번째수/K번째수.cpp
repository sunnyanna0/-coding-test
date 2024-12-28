#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sub;
    int i, j, k;
    for(int m=0 ; m<commands.size() ; m++){
        i=commands[m][0]-1;
        j=commands[m][1]-1;
        k=commands[m][2]-1;
        sub={}; //초기화
        
        for(int n=i ; n<=j ; n++){
            sub.push_back(array[n]);
        }
        sort(sub.begin(), sub.end());
        answer.push_back(sub[k]);
    }
    
    return answer;
}