import sys
input = sys.stdin.readline

# 가장 빨리 끝나는 회의
n = int(input())
meetings = []
for i in range(n):
    s, e = map(int, input().split())
    meetings.append((s, e))

fastest_end_time = 1000
real_time = 0
count = 0

meetings.sort(key=lambda x: (x[1], x[0]))
# print(meetings[1][0])

for i in range(n): # 가장 빨리 끝나는 회의 찾기
    if meetings[i][0]>=real_time:
        # fastest_end_time = min(fastest_end_time, meetings[i][1])
        real_time = meetings[i][1]
        count+=1
    

print(count)

