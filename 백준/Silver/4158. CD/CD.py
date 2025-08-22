import sys
input = sys.stdin.readline

while(1):
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    cd_a = []
    cd_b = []

    # for _ in range (n):
    #     cd_a.append(input().strip())
    # for _ in range (m):
    #     cd_b.append(input().strip())

    cd_a = [int(input()) for _ in range(n)]
    cd_b = [int(input()) for _ in range(m)]

    # finish = input() # 0 0 이게 왜 있는걸까?

    count = 0
    i=0
    j=0

    while(i<n and j<m):
        if cd_a[i] == cd_b[j]:
            count+=1
            i+=1
            j+=1
            # print(f"cd_a[i] == cd_b[j]")
        elif cd_a[i] > cd_b[j]:
            j+=1
            # print(f"d_a[i] > cd_b[j]")
        else:
            i+=1
            # print(f"d_a[i] < cd_b[j]")


    print(count)