import sys
input = sys.stdin.readline

n = int(input())
a, b = input().strip().split('*')

for _ in range(n):
    s = input().strip()

    # 길이 체크 (겹침 방지)
    if len(s) < len(a) + len(b):
        print("NE")
        continue

    # prefix / suffix 직접 비교
    if s[0:len(a)] == a and s[-len(b):] == b:
        print("DA")
    else:
        print("NE")
