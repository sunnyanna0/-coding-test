def solution(book_time):
    
    book_time.sort(key=lambda x: x[0])
    
    answer = 1
    avail_room = [[(0, 1449)]]
    for start, end in book_time:
        s_h, s_m = map(int, start.split(":"))
        total_start = s_h * 60 + s_m

        e_h, e_m = map(int, end.split(":"))
        total_end = e_h * 60 + e_m + 10
        
        add_room = True
        
        for room_slots in avail_room:
            found_slot = False # 이 방에서 빈 자리를 찾았는지 표시
            for i, (room_start, room_end) in enumerate(room_slots):
                if room_start <= total_start and total_end <= room_end:
                    room_slots.pop(i)
                    if room_start < total_start:
                        room_slots.append((room_start, total_start - 1))
                    if total_end < room_end:
                        room_slots.append((total_end, room_end))
                    
                    add_room = False
                    found_slot = True
                    break # 현재 방에서 배정 성공했으니 빈 시간 찾기 중단
            
            if found_slot:
                break
                
        if add_room:
            answer+=1
            
            new_room = []
            if 0 < total_start:
                new_room.append((0, total_start - 1))
            if total_end < 1450:
                new_room.append((total_end, 1449))
            avail_room.append(new_room)
    
    # print(avail_room)
    return answer