# 몇개 뜯는지는 X
# 그리디? -> 양옆의 합이 훨 큰거면...안됨
# dp?
# 정렬? 안됨
# 큰 순서로 번호를 매긴뒤? 
# 양옆의 값이 가운데보다 크면 양옆을 고르고, 아니면 가운데를 고름. 이걸 반복 -> 재귀?

# ----
# 테케는 다 맞았는데 7.5점이 나옴 ㅋ
# 반례: [3,2,2]

# def pick(sticker, left, mid, right):
#     global answer
#     global vis
    
#     if mid==0: # start
#         left = len(sticker)-1
#     elif mid==len(sticker)-1: # end
#         right = 0
#     ####
#     if sticker[mid]>=sticker[left]+sticker[right] and vis[mid]!=1:
#         answer+=sticker[mid]
#         sticker[mid]=0
#         vis[mid]=1
#         vis[left]=1
#         vis[right]=1
#     else:
#         sticker[mid]=0
#         vis[mid]=1
#         if vis[right]!=1: pick(sticker, right-1, right, right+1)
#         if vis[left]!=1: pick(sticker, left-1, left, left+1)
    
    

# def solution(sticker):
#     global answer
#     global vis
#     answer = 0
#     vis = [0]*(len(sticker))
#     for i in range(len(sticker)):
#         if vis[i]!=1: pick(sticker, i-1, i, i+1)

#     return answer


### ---- dp로 다시
def solution(sticker):
    n = len(sticker)
    
    # 스티커가 1장뿐인 경우는 바로 리턴
    if n == 1:
        return sticker[0]
    
    # case 1: 0번 뜯기
    dp1 = [0] * n
    dp1[0] = sticker[0]
    dp1[1] = max(sticker[0], sticker[1])
    
    # sticker[mid] + best_from(mid+2), # mid 선택
    # best_from(mid+1) # mid 포기
    # 이게 점화식이지만 dp에서는 반대이므로... -로 생각
    
    # i번째를 안 뜯으면: dp1[i-1]
    # i번째를 뜯으면: dp1[i-2] + sticker[i]
    #   이 둘 중 더 큰 값을 선택
    for i in range(2, n - 1):  # n-1(마지막)은 못 뜯으니까 n-2까지만
        dp1[i] = max(dp1[i-1], dp1[i-2] + sticker[i])
    
    case1 = dp1[n-2]
    
    # case 2: 0번 안뜯기
    dp2 = [0] * n
    dp2[1] = sticker[1]  # 1번부터 시작
    # 여기서는 "실질적인 0번째"가 sticker[1]이라고 생각하고 진행
    for i in range(2, n):
        dp2[i] = max(dp2[i-1], dp2[i-2] + sticker[i])
    
    case2 = dp2[n-1]  # 1 ~ n-1 구간의 최댓값
    
    return max(case1, case2)