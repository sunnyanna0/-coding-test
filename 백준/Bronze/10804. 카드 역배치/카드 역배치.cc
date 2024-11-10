#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void turn(vector<int>& A, int x, int y) {
    reverse(A.begin() + x - 1, A.begin() + y);
}

int main() {
    vector<int> A;
    for(int i = 0; i < 20; i++) {
        A.push_back(i + 1);
    }
    
    int a, b;
    for(int j = 0; j < 10; j++) {
        cin >> a >> b;
        turn(A, a, b);
    }
    
    for(int k = 0; k < A.size(); k++) {
        cout << A[k] << " ";
    }
    cout << endl;
}