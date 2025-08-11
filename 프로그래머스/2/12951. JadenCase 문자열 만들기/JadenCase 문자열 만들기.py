def solution(s):
    answer = ''
    s = s.lower()
    word = s.split(' ')
    print(word)
    for i, w in enumerate(word):
        if w == "":  # 빈 문자열인 경우 넘김
            continue
        if w[0].isdigit():
            continue
        else:
            word[i] = w.title()
        print(w)
    print(word)
    answer = ' '.join(word)
    return answer