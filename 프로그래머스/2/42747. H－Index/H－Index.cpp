#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = citations.size();
    int num=0;
    sort(citations.begin(), citations.end());
    while(1){
        num=0;
        for(int i=0; i<citations.size() ; i++){
            if(citations[i]>=answer){
                num++;
            }
        }
        if(num>=answer){
            break;
        }
        else{
            answer--;
        }
    }

    return answer;
}