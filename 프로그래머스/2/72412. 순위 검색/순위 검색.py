from collections import defaultdict
from bisect import bisect_left

def solution(info, query):
    # 0) 전처리: info -> db[key(str)] = sorted list of scores
    db = defaultdict(list)
    for line in info:
        a, b, c, d, s = line.split()
        score = int(s)
        fields = [a, b, c, d]
        # 16개 조합 (원소 또는 '-')
        for mask in range(16):
            key_parts = []
            for k in range(4):
                key_parts.append(fields[k] if (mask & (1 << k)) == 0 else "-")
            db[" ".join(key_parts)].append(score)

    # 각 버킷 정렬 (이분탐색 준비)
    for k in db:
        db[k].sort()

    # 1) 쿼리는 기존 바깥 루프를 유지
    answer = []
    for i in range(len(query)):
        # 2) and 제거 → key/score 추출
        tokens = query[i].replace(" and ", " ").split()
        key = " ".join(tokens[:4])  # 문자열 키, 입력 형식 그대로
        need = int(tokens[4])

        # 3) 이분탐색으로 개수 계산
        arr = db.get(key, [])
        idx = bisect_left(arr, need)       # need 이상이 처음 나오는 위치
        count = len(arr) - idx
        answer.append(count)

    return answer
