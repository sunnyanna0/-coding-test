#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weight_sum=0;
    vector<pair<int, int>> crossing;
    while(truck_weights.size()>0 || crossing.size()>0){
        answer++;
        
        for(int i =0 ; i<crossing.size() ; i++){
            if(crossing[i].second==0){
                weight_sum-=crossing[i].first;
                crossing.erase(crossing.begin());
            }
        }
        
        if(!truck_weights.empty() && weight_sum + truck_weights[0] <= weight){
            weight_sum+=truck_weights[0];
            crossing.push_back(make_pair(truck_weights[0], bridge_length));
            truck_weights.erase(truck_weights.begin());
        }
        for(int i =0 ; i<crossing.size() ; i++){
            crossing[i].second--;
        }
    }
    return answer;
}