#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> v(200000, 0);
    for(int i = 0  ; i<nums.size() ; i++){
        v[nums[i]]++;
    }
    int v_size = 0;
    for(int i = 0 ; i<v.size() ; i++){
        if(v[i]>=1){
            v_size++;
        }
    }
    if (v_size>nums.size()/2){
        answer = nums.size()/2;
    }
    else{
        answer = v_size;
    }
    return answer;
}