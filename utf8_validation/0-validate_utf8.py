#!/usr/bin/python3

"""UTF-8 Checking
"""

def validUTF8(data):
    """Checks if a list of numbers forms a valid UTF-8 data

    Args:
        data: list to check
    
    Returns:
        True if list is actually valid, 0 otherwise.
    """
    offset = 0
    k = 0

    while k < len(data):
        dec_to_bin = bin(data[k]).removeprefix('0b').zfill(8)[-8:]

        if not dec_to_bin.startswith('10'):
            offset = 0

            if dec_to_bin.startswith('110'):
                offset = 1
            if dec_to_bin.startswith('1110'):
                offset = 2
            elif dec_to_bin.startswith('11110'):
                offset = 3
        else:
            return False

        is_offset_in = False
        if k + offset < len(data):
            is_offset_in = True

        if is_offset_in:
            if offset:
                complete_code = data[k+1:k+offset+1]
                for i in complete_code:
                    dec_to_bin = bin(i).removeprefix('0b').zfill(8)[-8:]
                    if not dec_to_bin.startswith('10'):
                        return False
        else:
            return False

        k += offset
        k += 1

    if offset == 0:
        return True
    return False
