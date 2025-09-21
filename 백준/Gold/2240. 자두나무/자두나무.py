# 자두가 받을 수 있는 자두의 개수를 구해내는 프로그램
import sys
input = sys.stdin.readline

t, w = map(int, input().split())

jadu_position = 1
tree = [] #t-1초에 해당 나무에서 떨어짐
for i in range(t):
    tt = int(input())
    tree.append(tt%2)

count = 0

dp = [[0]*(w+1)for _ in range(t+1)] # dp[t][w] t초까지 진행했고 이동을 w번 했을 떄 먹을 수 있는 자두의 최대 갯수

for i in range(t):                 # i = 0..t-1
    fall = tree[i]                 # i번째 초에 떨어지는 나무(0/1)
    max_moves = min(w, i+1)        # i초까지 가능한 최대 이동 수
    for moves in range(max_moves+1):
        pos = 1 if moves % 2 == 0 else 0   # 현재 위치 (짝수=1번, 홀수=0번)
        gain = 1 if fall == pos else 0

        if moves == 0:
            dp[i+1][0] = dp[i][0] + gain
        else:
            dp[i+1][moves] = max(dp[i][moves], dp[i][moves-1]) + gain

        
        
print(max(dp[t]))
        
# 같은 (시간, 이동횟수) 조합을 계속 다시 계싼하게 되므로 부분문제가 겹침. --> dp