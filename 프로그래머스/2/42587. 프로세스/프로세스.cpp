#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    while(priorities.size()>0){
        if(*max_element(priorities.begin(), priorities.end())==priorities[0]){
            priorities.erase(priorities.begin());
            answer++;
            if(location==0){
                break;
            }
            else{
                location--;
            }
        }
       else{
           if(location==0){
               location+=priorities.size()-1;
               //cout<<"size: "<<priorities.size();
           }
           else{
               location--;
           }
           priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
        }
    }
    return answer;
}