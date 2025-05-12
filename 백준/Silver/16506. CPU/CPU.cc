#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, string> um;

// 이진수 문자열로 바꾸는 함수
string getBinary(int n, char flag) {
    string res = "";
    while (n) {
        if (n % 2 == 1) res.insert(0, "1");
        else res.insert(0, "0");
        n /= 2;
    }

    // 최소 3자리로 채움 (레지스터용)
    while (res.size() < 3) {
        res.insert(0, "0");
    }

    if (flag == '1') {
        // 즉시값(4비트용)은 4자리로 채움
        while (res.size() < 4) {
            res.insert(0, "0");
        }
    } else if (flag == '0') {
        // B타입이면 뒤에 0 하나 추가 (총 4비트 만들기)
        res += "0";
    }

    return res;
}

int main(void) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    // OPCODE 매핑
    um["ADD"] = "000000";
    um["ADDC"] = "000010";
    um["SUB"] = "000100";
    um["SUBC"] = "000110";
    um["MOV"] = "001000";
    um["MOVC"] = "001010";
    um["AND"] = "001100";
    um["ANDC"] = "001110";
    um["OR"] = "010000";
    um["ORC"] = "010010";
    um["NOT"] = "010100";
    um["MULT"] = "011000";
    um["MULTC"] = "011010";
    um["LSFTL"] = "011100";
    um["LSFTLC"] = "011110";
    um["LSFTR"] = "100000";
    um["LSFTRC"] = "100010";
    um["ASFTR"] = "100100";
    um["ASFTRC"] = "100110";
    um["RL"] = "101000";
    um["RLC"] = "101010";
    um["RR"] = "101100";
    um["RRC"] = "101110";

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string answer = "", opcode;
        int a, b, c;
        cin >> opcode >> a >> b >> c;

        answer += um[opcode];                        // 6비트 OPCODE
        answer += getBinary(a, 'X');                 // RD (3비트)
        answer += getBinary(b, 'X');                 // RA (3비트)
        answer += getBinary(c, answer[4]);           // RB or IMM (C타입 여부는 OPCODE 5번째 비트로 확인)

        cout << answer << "\n";
    }

    return 0;
}
