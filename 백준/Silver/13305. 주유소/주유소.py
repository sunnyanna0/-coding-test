import sys
input = sys.stdin.readline

n = int(input())
edge = list(map(int, input().split()))
node = list(map(int, input().split()))

money_sum = 0
min_price = node[0]

for i in range(n-1):
    if node[i] < min_price:
        min_price = node[i]
    money_sum += min_price * edge[i]

print(money_sum)
