import sys
input = sys.stdin.readline

MOD = 1_000_000_007
n, m = map(int, input().split())

dp = [0] * (n + 1)
dp[0] = 1  # 아무 것도 안 쓰는 한 가지

for i in range(1, n + 1):
    dp[i] = dp[i - 1]          # 마지막에 1초 스킬
    if i >= m:
        dp[i] = (dp[i] + dp[i - m]) % MOD  # 마지막에 m초 스킬
    else:
        dp[i] %= MOD

print(dp[n] % MOD)