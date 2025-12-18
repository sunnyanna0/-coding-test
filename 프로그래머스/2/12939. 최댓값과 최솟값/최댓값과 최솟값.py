def solution(s):
    nums = list(map(int, s.split()))
    
    min_val = nums[0]
    max_val = nums[0]
    
    for n in nums:
        max_val = max(max_val, n)
        min_val = min(min_val, n)
            
    return f"{min_val} {max_val}"
