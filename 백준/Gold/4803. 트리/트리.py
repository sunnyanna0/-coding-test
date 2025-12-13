def dfs(u, parent):
    vis[u] = True
    for v in range(1, n + 1):
        if graph[u][v] == 0:
            continue
        if not vis[v]:
            if not dfs(v, u):
                return False
        elif v != parent:
            return False
    return True

case = 1
while True:
    n, e = map(int, input().split())
    if n == 0 and e == 0:
        break

    graph = [[0] * (n + 1) for _ in range(n + 1)]
    vis = [False] * (n + 1)

    for _ in range(e):
        a, b = map(int, input().split())
        graph[a][b] = 1
        graph[b][a] = 1

    tree_count = 0
    for i in range(1, n + 1):
        if not vis[i]:
            if dfs(i, 0):
                tree_count += 1

    if tree_count == 0:
        print(f"Case {case}: No trees.")
    elif tree_count == 1:
        print(f"Case {case}: There is one tree.")
    else:
        print(f"Case {case}: A forest of {tree_count} trees.")
    case += 1