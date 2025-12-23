# 포도주 잔을 선택하면 모두 마셔야 함. 마신 후 원래 위치에 놓아야 함
# 연속으로 3잔 마실 수 없음
# 많은 양의 포도주를 맛보기 위해 어떤 포도주 잔을 선택해야하는가?

import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
wine = []

for _ in range (n):
    temp = int(input())
    wine.append(temp)

if n == 1:
    print(wine[0])
    sys.exit()
if n == 2:
    print(wine[0] + wine[1])
    sys.exit()

dp = [0]*n
dp[0] = wine[0]
dp[1] = wine[0] + wine[1]
dp[2] = max(dp[1], wine[1]+wine[2], wine[0]+wine[2])

for i in range(3, n):
    dp[i] = max(
        dp[i-1],                      # 안 마심
        dp[i-2] + wine[i],            # 1연속
        dp[i-3] + wine[i-1] + wine[i] # 2연속
    )

print(dp[n-1])