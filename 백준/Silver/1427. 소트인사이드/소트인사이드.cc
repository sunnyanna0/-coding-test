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

    int x;
    vector<int> A;

    while (N>=0.9)
    {
        x=N%10;
        N=N/10;
        A.push_back(x);
    }

    sort(A.begin(), A.end());
    for(int i=A.size()-1 ; i>=0 ; i--){
        cout << A[i];
    }

}