#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A;
    int x;

    for(int i=0 ; i<N ; i++){
        cin >> x;
        A.push_back(x);
    }

    sort(A.begin(),A.end());

    for(int i=0 ; i<A.size() ; i++){
        cout << A[i] << '\n';
    }
}