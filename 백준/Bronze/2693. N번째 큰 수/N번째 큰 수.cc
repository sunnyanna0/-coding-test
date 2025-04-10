#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while (t--)
    {
        vector<int> v;
        for (int i = 0; i < 10; i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        cout<<v[7]<<"\n";
    }
    

    return 0;
}
