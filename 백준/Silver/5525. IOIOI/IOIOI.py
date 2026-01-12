import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
S = list(input())

answer = 0



def check(i, N):
    global answer
    can = True
    for _ in range(N):
        if i+2<len(S):
            if S[i+1]=='O' and S[i+2]=='I':
                i+=2
            else:
                can = False
        else:
            can = False
    if can:
        answer+=1
        # print(f'{i}')
        
    

for i in range(len(S)):
    if S[i] == 'I':
        check(i, N)
    else:
        continue

print(answer)