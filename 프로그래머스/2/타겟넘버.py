import sys
from collections import deque

input = sys.stdin.readline

def solution(numbers, target):
    answer = 0
    queue1 = deque()
    queue2 = deque()
    queue1.append(numbers[0] * 1)
    queue1.append(numbers[0] * (-1))
    # print(queue1)
    for n in numbers[1:]:
        # print(f"queue1 시작: {queue2}")
        while queue1:
            cur_x = queue1.popleft()
            queue2.append(cur_x + n * 1)
            queue2.append(cur_x + n * (-1))
            # print(f"queue2 저장: {queue2}")

        queue1, queue2 = queue2, queue1
        # print(f"queue1: {queue1}")
        # print(f"queue2: {queue2}")
        queue2.clear()
        # print(f"queue1 마지막: {queue1}")
    # print(queue1)
    while queue1:
        final = queue1.popleft()
        if final == target:
            answer += 1

    return answer