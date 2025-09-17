import sys
input = sys.stdin.readline

s = input().split('-')
sum = 0
first_input = True

for i in range(len(s)):
    s_plus = s[i].split('+')
    sum_i = 0
    # print("aaa")
    # print(((len(s_plus[i]))//2)+1)
    # print(len(s_plus[i]))
    # print(s_plus[i])
    # print((s_plus))
    # print(len(s_plus))
    for j in range((len(s_plus))):
        # print("fdfd")
        # print(s_plus[j])
        sum_i += int(s_plus[j])
    if first_input:
        sum = sum_i
        first_input = False
    else:
        sum -= sum_i
    # print(sum)

print(sum)