import sys
input = sys.stdin.readline

N, game_type = input().split()
N = int(N)

people = set() # 처음에 딕셔너리로 썼다가, set이 더 간편한듯
for i in range(N):
    people.add(input().strip())

count = 0

if game_type=='Y':
    if N+1<2:
        count=0
    while len(people)>=2-1:
            
            temp = people.pop()
            # print(temp)
            # print(f"남은 set: {people}")
            count+=1

elif game_type=='F':
    if N+1<3:
        count=0
    while len(people)>=3-1:
            people.pop()
            people.pop()
            count+=1
else:
    if N+1<4:
        count=0
    while len(people)>=4-1:
            people.pop()
            people.pop()
            people.pop()
            count+=1

print(count)