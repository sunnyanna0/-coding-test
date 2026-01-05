import sys
input = sys.stdin.readline

N = int(input())
answer_white = 0
answer_blue = 0
board = []
for i in range(N):
    board.append(list(map(int, input().split())))

def solve(x, y, n):
    global answer_white, answer_blue
    
    color = board[x][y]
    for i in range(x, x + n):
        for j in range(y, y + n):
            if board[i][j] != color:
                next_n = n // 2
                solve(x, y, next_n)
                solve(x, y + next_n, next_n)
                solve(x + next_n, y, next_n)
                solve(x + next_n, y + next_n, next_n)
                return

    # 반복문을 무사히 통과했다면 모두 같은 색임
    if color == 0:
        answer_white += 1
    else:
        answer_blue += 1

solve(0, 0, N)
print(answer_white, answer_blue)