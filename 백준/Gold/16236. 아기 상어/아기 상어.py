import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
board = []
sx = sy = -1
for i in range(n):
    row = list(map(int, input().split()))
    for j in range(n):
        if row[j] == 9:
            sx, sy = i, j
            row[j] = 0           # 시작칸은 빈칸으로
    board.append(row)

# 위, 왼, 오른, 아래 (tie-break에 유리)
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

def bfs(sx, sy, size):
    """도달 가능한 먹이 중 (최단거리 → 가장 위 → 가장 왼쪽) 반환.
       없으면 None."""
    dist = [[-1]*n for _ in range(n)]
    q = deque([(sx, sy)])
    dist[sx][sy] = 0

    candidates = []
    min_d = None

    while q:
        x, y = q.popleft()
        d = dist[x][y]
        # 이미 더 짧은 먹이를 찾았으면 그 거리보다 멀리 안 탐색
        if min_d is not None and d > min_d:
            continue
        for k in range(4):
            nx, ny = x+dx[k], y+dy[k]
            if 0 <= nx < n and 0 <= ny < n and dist[nx][ny] == -1:
                # 지나갈 수 있는 칸: 상어 크기 이하
                if board[nx][ny] <= size:
                    dist[nx][ny] = d + 1
                    # 먹을 수 있는 물고기: 1..size-1
                    if 0 < board[nx][ny] < size:
                        if min_d is None or d+1 <= min_d:
                            min_d = d + 1
                            candidates.append((d+1, nx, ny))
                    q.append((nx, ny))

    if not candidates:
        return None
    candidates.sort(key=lambda t: (t[0], t[1], t[2]))  # 거리, x, y
    return candidates[0]  # (dist, x, y)

time = 0
size = 2
eat = 0
x, y = sx, sy

while True:
    res = bfs(x, y, size)
    if res is None:
        break
    d, nx, ny = res
    time += d
    eat += 1
    board[nx][ny] = 0
    x, y = nx, ny
    if eat == size:
        size += 1
        eat = 0

print(time)