def solution(elements):
    answer = 0
    s = set()
    for i in range(len(elements)):
        temp = 0
        for j in range(0, len(elements)):
            if i+j<len(elements)-1:
                temp = sum(elements[i:i+j+1])
                # print(f"sum1: {s}")
            else:
                temp = sum(elements[i:len(elements)+1])+sum(elements[0:j-(len(elements)-i)+1])
                # print(f"중간점검: i:{i}, j:{j} -> {elements[i:len(elements)+1]}, {elements[0:len(elements)-(j)+1]}")
                # print(f"sum3: {s}")
            s.add(temp)
    answer = len(s)
    # print(f"최종: {s}")
    return answer