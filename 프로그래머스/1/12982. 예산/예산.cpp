#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    int sum = budget;
    int i=0;
    while(sum>=0 && i<d.size()){
        if(sum-d[i]>=0){
            sum-=d[i];
            i++;
            answer++;
        }
        else{
            break;
        }
    }
    return answer;
}