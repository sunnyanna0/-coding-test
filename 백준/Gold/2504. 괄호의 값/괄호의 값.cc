#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;  // getline 사용 필요 없음, 한 줄 입력이므로 cin으로 처리
    stack<char> st;  // 괄호를 저장하는 스택
    stack<int> val;  // 값을 저장하는 스택
    bool isValid = true;  // 유효성 검사

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '['){
            st.push(s[i]);  // 괄호 스택에 추가
            val.push(-1);  // 아직 닫히지 않은 괄호 표시
        }
        else{
            int temp = 0;
            while (!val.empty() && val.top() != -1) {
                temp += val.top();
                val.pop();
            }

            if (val.empty() || st.empty() || 
                (s[i] == ')' && st.top() != '(') || 
                (s[i] == ']' && st.top() != '[')) {
                isValid = false;
                break;
            }

            val.pop(); // -1 제거
            st.pop();  // 괄호 스택에서도 제거

            if (s[i] == ')') {
                if (temp == 0) val.push(2); // 내부 값이 없으면 기본값
                else val.push(2 * temp); // 내부 값이 있으면 2를 곱함
            } 
            else if (s[i] == ']') {
                if (temp == 0) val.push(3);
                else val.push(3 * temp);
            }
        }
    }

    if (!st.empty() || !isValid) {  // 괄호가 남아 있거나 잘못된 입력이면 0 출력
        cout << "0";
    } else {
        int answer = 0;
        while (!val.empty()) {  // 남아 있는 값들을 합산
            answer += val.top();
            val.pop();
        }
        cout << answer;
    }
}
