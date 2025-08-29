import sys
input = sys.stdin.readline
from collections import deque

def solve():
    n, k = map(int, input().split())
    queue = deque([(0, 0)]) # (위치, 이동 횟수)
    vis = [False] * (n + 1)
    vis[0] = True

    while queue:
        cur_location, cur_count = queue.popleft()

        # 현재 위치가 이미 목표 지점에 도달했는지 확인
        if cur_location == n:
            print("minigimbob")
            return
        
        # 이동 횟수가 k를 초과하면 더 이상 탐색하지 않음
        if cur_count >= k:
            continue
        
        # 다음 이동 위치들
        next_locations = [cur_location + 1, cur_location + cur_location // 2]
        
        for nxt in next_locations:
            if nxt <= n and not vis[nxt]:
                vis[nxt] = True
                queue.append((nxt, cur_count + 1))
    
    print("water")

solve()