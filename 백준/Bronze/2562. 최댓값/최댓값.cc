#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int a;
    vector<int> v;
    for(int i=0 ; i<9 ; i++){
        cin>>a;
        v.push_back(a);
    }
    int max=0;
    int max_index=0;
    for(int i=0 ; i<9 ; i++){
        if(v[i]>max){
            max=v[i];
            max_index=i+1;
        }
    }
    cout<<max<<"\n"<<max_index;
}