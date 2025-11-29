from collections import deque

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def bfs(board, vis, x, y, w, h):
    queue = deque()
    queue.append((x, y))
    vis[x][y]=1
    

    while(queue):
        cur_x, cur_y = queue.popleft()
        
        if cur_x == h - 1 and cur_y == w - 1:
            return vis[cur_x][cur_y]

        for i in range(4):
            nx = cur_x + dx[i]
            ny = cur_y + dy[i]

            if nx>=h or ny>=w or nx<0 or ny<0:
                continue
            if vis[nx][ny]!=0:
                continue
            if board[nx][ny]==0:
                continue

            vis[nx][ny]= vis[cur_x][cur_y]+1
            queue.append((nx, ny))
    return -1
def solution(maps):
    answer = 0
    vis = [[0]*len(maps[0]) for _ in range(len(maps))]
    answer = bfs(maps, vis, 0, 0, len(maps[0]), len(maps))
    return answer

