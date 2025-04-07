#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int sum;
    int a=0;
    int b=1;
    for (int i = 1; i <= n/2; i++)
    {
        a=a+b;
        b=a+b;
    }
    if(n%2==0){
        cout<<a;
    }
    else{
        cout<<b;
    }
    
    return 0;
}
