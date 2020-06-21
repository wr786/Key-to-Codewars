def is_valid_walk(walk):
    pos = 0
    posFlag = {'n':10, 's':-10, 'w':-1, 'e':1}
    for dir in walk: pos = pos + posFlag[dir]
    return False if len(walk) != 10 else not pos