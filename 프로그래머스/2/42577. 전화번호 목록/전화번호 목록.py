def solution(phone_book):
    hash_map = {}
    for phone in phone_book:
        hash_map[phone] = 1
    
    for phone_number in phone_book:
        prefix = ""
        for digit in phone_number:
            prefix += digit
            if prefix in hash_map and prefix != phone_number:
                return False
                
    return True