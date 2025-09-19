# n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램
import math
import sys
input = sys.stdin.readline

def set_prime(n):

    # 에라토스테네스의 체 알고리즘
    for i in range(2, int(math.sqrt(n)) + 1):
        if not is_prime[i]: continue
        for j in range(2 * i, n + 1, i):
            is_prime[j] = False

while 1:
    n = int(input())
    if n==0:
        break
    answer = 0

    is_prime = [True] * (2*n + 1)  # 처음에는 모두 true로 초기화
    is_prime[1] = False  # 1은 소수가 아니므로

    set_prime(2*n)

    for i in range(n+1, 2*n+1):
        if is_prime[i]:
            answer+=1

    print(answer)