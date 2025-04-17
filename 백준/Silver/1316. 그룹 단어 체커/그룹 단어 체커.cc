#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int sum = 0;

    while (n--) {
        string s;
        cin >> s;
        vector<int> vis(26, 0);
        bool isGroup = true;
        char prev = s[0];
        vis[prev - 'a'] = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] != prev) {
                if (vis[s[i] - 'a']) {
                    isGroup = false;
                    break;
                }
                vis[s[i] - 'a'] = 1;
                prev = s[i];
            }
        }

        if (isGroup) sum++;
    }

    cout << sum << '\n';
}
