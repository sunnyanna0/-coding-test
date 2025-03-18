#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);

    int floor=0;
    int answer=0;
    for(int  i=0 ; i<s.size() ; i++){
        if(s[i]=='('){
            floor++;
        }
        else{
            if(s[i-1]=='('){
                floor--;
                answer+=floor;
            }
            else{
                answer++;
                floor--;
            }
        }
    }

    cout<<answer;
    return 0;
}
