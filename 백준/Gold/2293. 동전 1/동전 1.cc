#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin>>n>>k;

    vector<int> v;
    vector<int> dp(k+1, 0); //크기를 k + 1로 만들고, 모든 원소를 0으로 채움
    dp[0] = 1; //0을 만드는 경우의서 1개

    for (int i = 0; i < n; i++)
    {
        int x;
        cin>> x;
        v.push_back(x);
    }

    for (int i = 0; i < n; i++) { // 동전 종류
        for (int j = v[i]; j <= k; j++) { // j: 만들고자 하는 금액
            dp[j] += dp[j - v[i]];
        }
    }
    
    cout<<dp[k];

    
    

    return 0;
}
