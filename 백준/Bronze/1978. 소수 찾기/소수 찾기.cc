#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool isPrime(int x) {
    if (x < 2) return false; // 0과 1은 소수가 아님
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    int sum=0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(isPrime(x)){
            sum++;
        }
        
    }
    cout<<sum;

    return 0;
}
