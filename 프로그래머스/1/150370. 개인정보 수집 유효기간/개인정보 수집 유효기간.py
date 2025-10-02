def solution(today, terms, privacies):
    answer = [] # 파기해야할 번호
    today_sum = 0

    for i in range(len(privacies)):
        privacies_date, privacies_type = privacies[i].split(' ')
        for j in range(len(terms)):
            terms_type, terms_month = terms[j].split()
            if privacies_type == terms_type:
                # print(f"privacies_type == terms_type = {privacies_type}=={terms_type}")
                p_y, p_m, p_d = map(int, privacies_date.split('.'))
                t_y, t_m, t_d = map(int, today.split('.'))
                p_sum = p_y*28*12 + p_m*28 + p_d
                t_sum = t_y*28*12 + t_m*28 + t_d
                print(f"p_sum + int(terms_month)*28 -1 <= t_sum ===> {p_sum} + {int(terms_month)*28} -1 <= {t_sum}")
                print(f"p_sum + int(terms_month)*28 -1 <= t_sum ===> {p_sum + int(terms_month)*28 -1} <= {t_sum}")
                temp = t_sum - int(terms_month)*28 -1
                if p_sum + int(terms_month)*28 -1 < t_sum:
                    answer.append(i+1)
    return answer