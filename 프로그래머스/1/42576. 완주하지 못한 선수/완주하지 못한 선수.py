from collections import Counter

def solution(participant, completion):
    answer = ''
    count = Counter(participant)
    for name in completion:
        count[name] -= 1

    for name in count:
        if count[name]==1:
            answer = name
    return answer
