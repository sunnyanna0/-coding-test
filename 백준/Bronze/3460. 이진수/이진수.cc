#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void print_bit_positions(int n) {
    int pos = 0;
    while (n > 0) {
        if (n & 1) {
            cout << pos << " ";
        }
        n >>= 1;  // 오른쪽으로 한 칸 shift
        pos++;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    vector<int> v;
    while(t--){
        int x;
        cin>>x;
        // v.push_back(x);
        print_bit_positions(x);
    }
    return 0;
}
