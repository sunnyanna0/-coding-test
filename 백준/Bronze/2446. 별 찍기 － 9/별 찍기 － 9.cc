#include <iostream>
using namespace std;

int main(void){
    int a;
    cin>>a;

    for(int i=0 ; i<a ; i++){
        for(int j=0 ; j<i ; j++){
            cout<<" ";
        }
        for(int j=0 ; j<(a*2-1)-i*2 ; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=a+1 ; i<=a*2-1 ; i++){
        for(int j=0 ; j<(a*2-1)-i ; j++){
            cout<<" ";
        }
        for(int j=0 ; j<-((a*2-1)-i*2) ; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}