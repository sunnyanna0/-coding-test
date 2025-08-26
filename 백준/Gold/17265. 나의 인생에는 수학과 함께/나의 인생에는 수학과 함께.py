import sys
input = sys.stdin.readline
from collections import deque

dx = [1, 0]
dy = [0, 1]

n = int(input())
board = [list(input().split()) for _ in range(n)]

answer_min = 10000000
answer_max = -1000000

def bfs(x, y, n):
    global answer_max, answer_min
    queue = deque()
    queue.append((x, y, int(board[x][y]), None))

    while(queue):
        cur_x, cur_y, value, op = queue.popleft()

        if cur_x == n - 1 and cur_y == n - 1:
            answer_min = min(answer_min, value)
            answer_max = max(answer_max, value)
            continue

        for i in range(2):
            nx = cur_x+dx[i]
            ny = cur_y + dy[i]

            if nx>=n or ny>=n or nx<0 or ny<0:
                continue
            if (nx+ny) % 2 == 1:  # 연산자 칸
                queue.append((nx, ny, value, board[nx][ny]))   # op 갱신
            else:  # 숫자 칸
                if op == '+':
                    new_val = value + int(board[nx][ny])
                elif op == '-':
                    new_val = value - int(board[nx][ny])
                else:  # '*'
                    new_val = value * int(board[nx][ny])
                queue.append((nx, ny, new_val, None))  # 숫자 칸은 연산 끝냈으니 op 초기화


bfs(0, 0, n)
print(answer_max, answer_min)
