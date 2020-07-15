def first_non_repeating_letter(string):
    for i in range(len(string)):
        if string[i].lower() not in (string[:i]+string[i+1:]).lower(): return string[i]
    return ''