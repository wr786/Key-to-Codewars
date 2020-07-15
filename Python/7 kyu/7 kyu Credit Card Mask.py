# return masked string
def maskify(cc):
    return '#' * max(0, len(cc)-4) + cc[-4:]