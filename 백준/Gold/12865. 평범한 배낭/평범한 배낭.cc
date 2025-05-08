#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    dp[0][0]=0;

    vector<int> weight;
    vector<int> value;
    for (int i = 1; i <= n; i++)
    {
        int w, v;
        cin>>w>> v;
        weight.push_back(w);
        value.push_back(v);
        
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= k; w++) {
            if (weight[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weight[i-1]] + value[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout<<dp[n][k];
}
