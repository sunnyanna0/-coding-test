import sys
input = sys.stdin.readline

m, n = map(int, input().split())
snack = list(map(int, input().split()))
# snack = sorted(snack)

def pieces(L):
    # 길이 L로 자르면 전체 몇 조각 나오는지
    return sum(x // L for x in snack)

lo, hi = 1, max(snack)  # L의 탐색 범위
ans = 0
can_eat = True
while lo <= hi:
    mid = (lo + hi) // 2  # 후보 길이 L
    if pieces(mid) >= m:  # m명에게 줄 수 있다 → 더 길게 시도
        ans = mid
        lo = mid + 1
    else:                 # 못 준다 → 더 짧게
        hi = mid - 1

print(ans)