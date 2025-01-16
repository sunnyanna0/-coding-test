#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
    int n;
    cin>>n;
    int sum=0;
    vector<int> v;
    int a;
    for(int i=0 ; i<n ; i++){
        cin>>a;
        if(a==0){
            v.pop_back();
        }
        else{
            v.push_back(a);
        }
    }
    for(int i=0 ; i<v.size() ; i++){
        sum+=v[i];
    }
    cout<<sum;
}