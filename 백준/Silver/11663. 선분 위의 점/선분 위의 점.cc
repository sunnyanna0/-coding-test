#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int start, end=0;

    int left = lower_bound(v.begin(), v.end(), start) - v.begin();
    int right = upper_bound(v.begin(), v.end(), end) - v.begin();
    int count = right - left;

    for (int i = 0; i < m; i++)
    {
        cin>>start>>end;
        int dot_start, dot_end=0;
        dot_start=v[0];
        dot_end=v.back();
        
        int left = lower_bound(v.begin(), v.end(), start) - v.begin();
        int right = upper_bound(v.begin(), v.end(), end) - v.begin();
        int count = right - left;

        cout<<count<<"\n";
    }

    return 0;
}
