def solution(args):
    ret = []
    last = args[0]
    combo = 1
    for i in range(1, len(args)):
        if args[i] != last + combo:
            if combo > 2: ret.append(f'{last}-{args[i-1]}')
            elif combo == 1: ret.append(str(last))
            else:
                ret.append(str(last))
                ret.append(str(args[i-1]))
            last = args[i]
            combo = 1
        else: combo += 1
    if combo > 2: ret.append(f'{last}-{args[len(args)-1]}')
    elif combo == 1: ret.append(str(last))
    else:
        ret.append(str(last))
        ret.append(str(args[len(args)-1]))
    return ','.join(ret)