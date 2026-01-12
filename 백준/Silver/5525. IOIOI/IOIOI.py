import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
S = list(input())

answer = 0
cnt = 0
i = 1

while i < M - 1:
    if S[i-1] == 'I' and S[i] == 'O' and S[i+1] == 'I':
        cnt += 1
        if cnt >= N:
            answer += 1
            cnt -= 1   # 겹침 처리
        i += 2         # 다음 'OI'로 점프
    else:
        cnt = 0
        i += 1

print(answer)