#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> person1;
    vector<int> person2;
    vector<int> person3;
    int size=0;
    int point1=0, point2=0, point3=0;
    while(size<answers.size()){
        for(int j=1 ; j<=5 ; j++){
            person1.push_back(j);
            size++;
        }
    }
    size=0;
    while(size<answers.size()){
        for(int j=1 ; j<=5 ; j++){
            if(j!=2){
                person2.push_back(2);
                size++;
                person2.push_back(j);
                size++;
            }
        }
    }
    size=0;
    while(size<answers.size()){
        for(int j=0 ; j<2 ; j++){
            person3.push_back(3);
            size++;
        }
        for(int j=0 ; j<2 ; j++){
            person3.push_back(1);
            size++;
        }
        for(int j=0 ; j<2 ; j++){
            person3.push_back(2);
            size++;
        }
        for(int j=0 ; j<2 ; j++){
            person3.push_back(4);
            size++;
        }
        for(int j=0 ; j<2 ; j++){
            person3.push_back(5);
            size++;
        }
    }
    for(int i=0 ; i<answers.size() ; i++){
        if(answers[i]==person1[i]) point1++;
        if(answers[i]==person2[i]) point2++;
        if(answers[i]==person3[i]) point3++;
    }
    int maximum=max({point1, point2, point3});
    if(maximum==point1) answer.push_back(1);
    if(maximum==point2) answer.push_back(2);
    if(maximum==point3) answer.push_back(3);
    sort(answer.begin(), answer.end());
    return answer;
}