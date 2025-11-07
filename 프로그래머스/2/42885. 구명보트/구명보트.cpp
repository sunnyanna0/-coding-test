#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size()-1;
    while(left<=right){
        answer++;
        if(people[right]+people[left]<=limit){
            left++;
        }
        right--;
    }
    
    return answer;
}