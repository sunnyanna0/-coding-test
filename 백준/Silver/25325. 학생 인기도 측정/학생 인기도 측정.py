import sys
input = sys.stdin.readline

n = int(input())
a = input().split()

name = {} # 중괄호는 딕셔너리
for i in range(n):
    name[a[i]] = 0

for i in range(n):
    temp = input().split()
    for popular in temp:
        name[popular]+=1

# sort(name) 리스트 전용임
name = sorted(name.items(), key=lambda x: (-x[1], x[0])) # 딕셔너리 전용

# 출력
for student, cnt in name:
    print(student, cnt)