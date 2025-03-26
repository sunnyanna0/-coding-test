#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        vector<int> v;
        int n, m;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        cin>>m;
        bool have=false;
        for (int i = 0; i < m; i++)
        {
            have=false;
            int x;
            cin>>x;
            cout << (binary_search(v.begin(), v.end(), x) ? "1\n" : "0\n");
            // for(int j=0 ; j<n ; j++){
            //     if(x==v[j]){
            //         have=true;
            //     }
            // }
            // if(have){
            //     cout<<"1\n";
            // }
            // else{
            //     cout<<"0\n";
            // }
        }
    }

    return 0;
}
