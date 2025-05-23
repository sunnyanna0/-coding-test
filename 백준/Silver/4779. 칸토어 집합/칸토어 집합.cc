#include <iostream>
#include <string>
using namespace std;

void cantor(string& s, int start, int len){
    if(len<3) return;

    int third = len/3;

    // 가운데 1/3을 공백으로 바꾸기
    for (int i = start + third; i < start + 2 * third; ++i) {
        s[i] = ' ';
    }

    // 양쪽 1/3에 대해 재귀 호출
    cantor(s, start, third);              // 왼쪽
    cantor(s, start + 2 * third, third);  // 오른쪽
}

int main(){
    int n;
    while(cin>>n){
        int len=1;
        string s;
        for (int i = 0; i < n; ++i) len *= 3;
        for (int i = 0; i < len; i++)
        {
            s+='-';
        }
        
        cantor(s, 0, len);

        cout<< s <<endl;
    }
}