def find_missing_letter(chars):
    return "".join([chr(x) if chr(x) not in chars else '' for x in range(ord(min(chars)), ord(max(chars))+1)])

