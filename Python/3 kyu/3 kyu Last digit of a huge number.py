def last_digit(lst):
    ret = 1
    for x in reversed(lst):
        ret = x ** (ret if ret < 4 else ret % 4 + 4)
    return ret % 10