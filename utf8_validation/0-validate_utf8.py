#!/usr/bin/python3
"""Define a method to validate UTF8 encoding
"""


def validUTF8(d):
    """Return a True statement for a valid utf8 encoding else return False
    """
    if not type(d) is list:
        return False

    for i in d:
        if not type(i) is int:
            return False

    offset = 0
    for i in d:
        '''Integer to string conversion
        '''
        binary_value = bin(i).replace("0b", "")
        binary_value = binary_value.zfill(8*int(len(binary_value)/9)+8)
        binary_size = int(len(binary_value)/8)

        if not 1 <= binary_size <= 4:
            return False

        '''Bytes Check
        '''
        if offset == 0:
            if binary_size == 2:
                if not binary_value[-8:].startswith('110'):
                    return False
                offset = 1
            elif binary_size == 3:
                if not binary_value[-8:].startswith('1110'):
                    return False
                offset = 2
            elif binary_size == 4:
                if not binary_value[-8:].startswith('11110'):
                    return False
                offset = 3
            else:
                if binary_value.startswith('10'):
                    return False
        else:
            if not binary_value[-8:].startswith('10'):
                return False
            offset -= 1

    '''
    If offset is not zero, there is an encoding error
    Else all characters are valid
    '''
    if not offset == 0:
        return False
    return True
