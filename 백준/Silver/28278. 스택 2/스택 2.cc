#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> st;

    while(n--) {
        int cmd;
        cin >> cmd;

        if(cmd == 1) {
            int x;
            cin >> x;
            st.push(x);
        }
        else if(cmd == 2) {
            if(st.empty()) cout << -1 << '\n';
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if(cmd == 3) {
            cout << st.size() << '\n';
        }
        else if(cmd == 4) {
            cout << (st.empty() ? 1 : 0) << '\n';
        }
        else if(cmd == 5) {
            if(st.empty()) cout << -1 << '\n';
            else cout << st.top() << '\n';
        }
    }
}
