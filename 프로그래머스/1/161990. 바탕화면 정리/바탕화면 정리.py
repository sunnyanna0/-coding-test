def solution(wallpaper):
    answer = []
    # col1, row1, col2, row2 = 0 # 이거 안됨. 아래처럼!
    col2 = row2 = 0
    row1 = col1 =  1000000
    
    for i in range(len(wallpaper)):
        for j in range(len(wallpaper[i])):
            if wallpaper[i][j] == '#':
                if row1>j:
                    row1=j
                if row2<j:
                    row2=j
                if col1>i:
                    col1=i
                if col2<i:
                    col2=i
    # print("test")
        
    # print(wallpaper[0][0])
    answer.append(col1)
    answer.append(row1)
    answer.append(col2+1)
    answer.append(row2+1)
    print(answer)
    return answer