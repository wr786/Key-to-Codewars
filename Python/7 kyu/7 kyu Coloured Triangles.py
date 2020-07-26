def triangle(row):
    while len(row) > 1:
        tmp = ''
        for i in range(1, len(row)):
            if row[i-1] == row[i]: tmp += row[i]
            else: tmp += list({'R', 'G', 'B'} - {row[i-1], row[i]})[0]
        row = tmp
    return row