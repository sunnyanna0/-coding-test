import sys
input = sys.stdin.readline
from collections import deque

n, m, a, b = map(int, input().split())
count_action = 0
count_puppy = 0
can_have = True

range_back_to=[]
queue = deque()

for i in range (m):
    temp1, temp2 = map(int, input().split())
    range_back_to.append((temp1, temp2))

queue.append((0, 0))
visited = [False] * (n + 1)
visited[0] = True

def blocked(x):
    for A, B in range_back_to:
        if A <= x <= B:   # 포함!
            return True
    return False

while queue:
    count_puppy, count_action = queue.popleft()
    if blocked(count_puppy):
        continue

    if count_puppy==n:
        can_have = True
        break
    if count_puppy>n:
        can_have = False
        continue


    nx = count_puppy + a
    if 0 <= nx <= n and not blocked(nx) and not visited[nx]:
        visited[nx] = True
        queue.append((nx, count_action + 1))

    nx = count_puppy + b
    if 0 <= nx <= n and not blocked(nx) and not visited[nx]:
        visited[nx] = True
        queue.append((nx, count_action + 1))

if can_have and count_puppy == n:
    print(count_action)
else:
    print(-1)