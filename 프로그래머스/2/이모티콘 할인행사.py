from itertools import product

def solution(users, emoticons):
    # 최적 해 (가입자 수, 매출)
    best_sign, best_money = 0, 0
    
    discount_rates = [10, 20, 30, 40]
    # 모든 할인 조합 (각 이모티콘에 10/20/30/40 중 하나)
    all_cases = product(discount_rates, repeat=len(emoticons))

    for case in all_cases:  # case: (r1, r2, ..., rM)
        sign = 0
        money = 0

        # 모든 사용자에 대해 합계 계산
        for min_rate, limit in users:
            total = 0
            for price, rate in zip(emoticons, case):
                if rate >= min_rate:  # 이 유저가 살 할인률인지
                    # 정수 계산(//)로 깔끔하게
                    total += price * (100 - rate) // 100

            # 유저 판단: 합계가 기준 이상이면 '가입', 아니면 매출에 더함
            if total >= limit:
                sign += 1
            else:
                money += total

        # 최적값 갱신: 가입자 우선, 같으면 매출 큰 것
        if sign > best_sign or (sign == best_sign and money > best_money):
            best_sign, best_money = sign, money

    return [best_sign, best_money]
