def digital_root(n):
    return digital_root(sum([int(c) for c in str(n)])) if n // 10 else n