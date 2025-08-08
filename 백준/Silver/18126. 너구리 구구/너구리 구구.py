import sys
from collections import deque
input = sys.stdin.readline

n = int(input())  # 1. 방(노드) 수 입력
graph = [[] for _ in range(n + 1)]  # 2. 인접 리스트 초기화

# 3. 간선 입력 받아 양방향 그래프 구성
for _ in range(n - 1):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

visited = [False] * (n + 1)  # 4. 방문 체크 리스트
dist = [0] * (n + 1)         # 5. 거리 저장 리스트

# 6. BFS 함수 정의
def bfs(start):
    queue = deque()
    queue.append(start)
    visited[start] = True

    while queue:
        node = queue.popleft()
        for neighbor, cost in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                dist[neighbor] = dist[node] + cost
                queue.append(neighbor)

# 7. BFS 탐색 시작 (입구는 1번)
bfs(1)

# 8. 최종 결과 출력
print(max(dist))
