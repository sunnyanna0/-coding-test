#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void) {
    string str;
    cin>>str;
    int m;
    cin>>m;

    char c;
    char d;
    list<char> L(str.begin(), str.end()); // 초기 문자열 처리
    //int cursor=L.size();
    auto cursor = L.end();
    for(int i=0 ; i<m ; i++){
        cin>>c;

        if (c == 'P') {
            cin >> d;
            L.insert(cursor, d);
        }
        else if (c == 'L') {
            if (cursor != L.begin()) cursor--;
        }
        else if (c == 'D') {
            if (cursor != L.end()) cursor++;
        }
        else { // 'B'
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for (auto c : L) cout << c;
}