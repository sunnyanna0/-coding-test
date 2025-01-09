#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int a;
    vector<int> v;
    for(int i=0 ; i<3 ; i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i=0 ; i<3 ; i++){
        cout<<v[i]<<" ";
    }
}