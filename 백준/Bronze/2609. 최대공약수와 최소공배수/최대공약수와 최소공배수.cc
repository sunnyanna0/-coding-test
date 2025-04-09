#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_min(int a, int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin>>a>>b;

    int min=10000;
    int max=0;
    for (int i = 1; i <= find_min(a, b); i++)
    {
        if(a%i==0 && b%i==0){
            if(max<i){
                max=i;
            }
        }
    }
    // while (b != 0) {
    //     int r = a % b;
    //     a = b;
    //     b = r;
    // }
    // min=a;
    
    cout<<max<<"\n"<<a*b/max;
    

    return 0;
}
