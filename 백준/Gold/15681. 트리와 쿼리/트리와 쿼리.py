import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N, R, Q = map(int, input().split())

connect = [[] for _ in range(N + 1)] # 입력 트리
parent = [0] * (N + 1) # 각 노드의 부모
tree = [[] for _ in range(N + 1)] # 각 노드의 자식 리스트

for _ in range(1, N):
    U, V = map(int, input().split())
    connect[U].append(V)
    connect[V].append(U)
    # connect[1] = [2, 3]
    # connect[2] = [1, 4, 5]
    # connect[3] = [1]
    # connect[4] = [2]
    # connect[5] = [2]

def makeTree(currentNode, parentNode): # 각 정점별로 부모가 누구인지, 자식들의 목록은 어떻게 되는지를 저장
    parent[currentNode] = parentNode
    for nxt in connect[currentNode]:
        if nxt == parentNode:
            continue
        tree[currentNode].append(nxt)
        makeTree(nxt, currentNode)

subtree_size = [0] * (N + 1)

def countSubtreeNodes(currentNode): # 모든 정점에 대해 해당 정점을 루트로 하는 서브트리에 속한 정점의 수를 계산하는 함수
    subtree_size[currentNode] = 1
    # 자식들에 대해 재귀 호출
    for child in tree[currentNode]:
        countSubtreeNodes(child)
        subtree_size[currentNode] += subtree_size[child]

makeTree(R, 0)
countSubtreeNodes(R)


for _ in range(Q):
    U = int(input())
    print(subtree_size[U])