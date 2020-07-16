def find_all(sum_dig, digs):
    ret = [0, None, None]
    def find(sum, digs, curNum):
        if digs == 0:
            if sum == 0:
                ret[0] += 1
                ret[1] = min(ret[1], curNum) if ret[1] else curNum
                ret[2] = max(ret[2], curNum) if ret[2] else curNum
        else:
            for num in range(curNum%10 if curNum else 1, min(sum // digs + 1, 10)):
                find(sum - num, digs - 1, curNum*10 + num)
    find(sum_dig, digs, 0)
    return ret if ret[1] else []
    