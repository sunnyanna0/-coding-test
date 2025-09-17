import sys
input = sys.stdin.readline

n = int(input())
edge = []*(n)
node = []*(n)

edge = list(map(int, input().split()))
node = list(map(int, input().split()))

money_sum = 0
can_go = 0
temp = 100000000
   
for i in range(n-1):
    for j in range(i+1):
        temp = min(temp, node[j])
    money_sum += temp*edge[i]

print(money_sum)