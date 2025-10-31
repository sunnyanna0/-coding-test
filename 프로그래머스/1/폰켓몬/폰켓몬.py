from collections import Counter

def solution(nums):
    answer = 0
    sum=len(nums)
    count = Counter(nums)
    if sum//2<=len(count):
        answer = sum//2
    else:
        answer = len(count)
    return answer