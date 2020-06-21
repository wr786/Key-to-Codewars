def sum_pairs(ints, s):
    mem = set()    # set is faster
    for x in ints: 
        if s-x in mem : return [s-x, x]
        mem.add(x)
    return None