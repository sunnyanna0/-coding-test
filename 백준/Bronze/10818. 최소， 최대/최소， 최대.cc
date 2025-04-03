#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>> x;
        v.push_back(x);

    }

    cout << *min_element(v.begin(), v.end())<<" "<< *max_element(v.begin(), v.end());

    return 0;
}
