import sys
input = sys.stdin.readline

n=int(input())
list = [0]*n
sum=0

for i in range(n):
    if i==0 or i==1 or i==2:
        list[i]=1
    else:
        list[i]=list[i-1]+list[i-2]
    sum+=list[i]

print(sum%10007)