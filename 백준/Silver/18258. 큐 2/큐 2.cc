#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0); //입출력 속도 향상
    cin.tie(NULL);  // 🚀 입력 속도 향상
    cout.tie(NULL); // 🚀 출력 속도 향상 (필수는 아님)
    
    queue<int> q;
    int n;
    cin >> n;
    string c;

    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c == "push")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (c == "pop")
        {
            if (q.empty())
                cout << "-1\n";
            else
            {
                cout << q.front() <<"\n";
                q.pop();
            }
        }
        else if (c == "size")
        {
            cout << q.size() <<"\n";
        }
        else if (c == "empty")
        {
            cout << (q.empty() ? "1" : "0") <<"\n"; // 🚨 삼항 연산자로 간결화
        }
        else if (c == "front")
        {
            if (q.empty())
                cout << "-1" <<"\n";
            else
                cout << q.front() <<"\n";
        }
        else if (c == "back")
        {
            if (q.empty())
                cout << "-1" <<"\n";
            else
                cout << q.back() <<"\n";
        }
    }
    return 0;
}
