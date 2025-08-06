import sys
input = sys.stdin.readline

n=int(input())
# weight = map(int,input().split()) # 이건 한 줄 입력을 정수로 바꾸는 map 객체. map() 객체는 정렬할 수 없음
weight = list(map(int, input().split()))

weight.sort()

total=0
# for w in range(weight): #weight는 리스트이고, range(weight)는 의미 없음
for w in weight:
    if w<=total+1:
        total+=w
    else:
        break

print(total+1)