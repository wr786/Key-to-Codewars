def decodeMorse(morse_code):
    # ToDo: Accept dots, dashes and spaces, return human-readable message
    return "".join([MORSE_CODE[seg] if seg != 's' else ' ' for seg in morse_code.strip().replace("   ", " s ").split(" ")])