import sys
import math
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    x, y = map(int, input().split())
    d = y - x
    if d == 0:
        print(0)
        continue

    k = int(math.isqrt(d))  # floor(sqrt(d))
    if d == k * k:
        print(2 * k - 1)
    elif d <= k * k + k:
        print(2 * k)
    else:
        print(2 * k + 1)
