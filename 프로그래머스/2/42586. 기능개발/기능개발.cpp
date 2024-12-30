#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int sum=0;
    while(progresses.size()>0){
        if(progresses[0]>=100){//첫번째가 100%면 지우기
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            sum++;
        }
        else{
            if(sum>0){
                answer.push_back(sum);
            }
            sum=0;
            
            for(int i=0 ; i<progresses.size() ; i++){
                progresses[i]+=speeds[i];
            }
        }

    }
    if(sum>0){
        answer.push_back(sum);
    }
    return answer;
}