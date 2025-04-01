#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin>>n>>k;
    int count=0;

    for (int i = 1; i <= n; i++)
    {
        if(n%i==0){
            count++;
            if(count==k){
                cout<<i;
            }
        }
    }
    
    if(count<k){
        cout<<"0";
    }

    return 0;
}
