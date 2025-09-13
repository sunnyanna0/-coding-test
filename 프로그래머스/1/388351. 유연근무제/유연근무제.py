def solution(schedules, timelogs, startday):
    answer = len(schedules)
    temp = startday
    print(answer)
    for i in range(len(schedules)):
        for j in range(7):
            startday=(j+temp)%7
            print(f"증가중: startday:{startday}")
            if startday==6 or startday==0:
                print(f"continue: startday:{startday}") # 0이 7을 의미
                continue
            else:
                # hours1 = timelogs[i][j]//100
                # min1 = timelogs[i][j]%100
                temp1 = (timelogs[i][j]//100)*60 + timelogs[i][j]%100
                temp2 = (schedules[i]//100)*60 + schedules[i]%100
                if temp1-temp2>10:
                    answer-=1
                    print(f"startday={startday}")
                    print(f"i, j = {i}, {j}")
                    
                    break
            
    return answer