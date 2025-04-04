#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int sum=0;
    int answer=0;
    for (int i = 0; i < 10; i++)
    {
        int m, p;
        cin>>m>>p;
        sum-=m; sum+=p;
        if(sum>answer){
            answer=sum;
        }
    }
    
    cout<<answer;
    
    return 0;
}
