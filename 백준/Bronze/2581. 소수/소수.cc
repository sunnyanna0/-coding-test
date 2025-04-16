#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x){

    if (x < 2) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin>>m>>n;

    int sum=0;
    int min=10001;
    bool havePrime=false;
    for (int i = m; i <= n; i++)
    {
        if(isPrime(i)){
            sum+=i;
            if(i<min){
                min=i;
            }
            havePrime=true;
        }
    }
    
    if(!havePrime){
        cout<<"-1"<<"\n";
    }
    else{
        cout<<sum<<"\n";
        cout<<min;
    }
    
}