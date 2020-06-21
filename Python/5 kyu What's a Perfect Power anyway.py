def isPP(n):
    for x in range(2, n // 2 + 1):
        if n % x == 0:
            tmp = n
            cnt = 0
            while tmp >= x and tmp % x == 0: 
                tmp //= x
                cnt += 1
            if tmp == 1: 
                return [x, cnt]
    return None
    