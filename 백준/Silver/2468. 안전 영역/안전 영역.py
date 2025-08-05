import sys
input = sys.stdin.readline
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y, board, vis, m, n, w):
    queue = deque()
    queue.append((x, y))
    vis[x][y] = 1

    while queue:
        cur_x, cur_y = queue.popleft()

        for dir in range(4):
            nx = cur_x + dx[dir]
            ny = cur_y + dy[dir]

            if nx < 0 or nx >= m or ny < 0 or ny >= n:
                continue
            if vis[nx][ny]:
                continue
            if board[nx][ny] <= w:
                continue

            vis[nx][ny] = 1
            queue.append((nx, ny))

n = int(input())

board = [list(map(int, input().split())) for _ in range(n)] # 2차원 배열 입력
max_count = 0

max_height = max(map(max, board)) # max()를 두 번 사용하는 이유는 바로 2차원 리스트

for w in range (max_height):
    vis = [[0]*n for _ in range(n)]
    count = 0

    for i in range (n):
        for j in range (n):
            # print(f"모든 i:{i}, j:{j}")
            if vis[i][j]==0 and board[i][j] > w:
                # print(f"bfs시작")
                # print(f"걸리면 i:{i}, j:{j}")
                bfs(i, j, board, vis, n, n, w)
                count+=1
                # print(f"count: {count}")
    if max_count<count:
        max_count=count

print(max_count)