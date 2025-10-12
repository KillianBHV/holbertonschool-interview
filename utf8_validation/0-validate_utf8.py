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
        binary_value = bin(i).replace("0b", "").zfill(8)[-8:]

        '''Bytes Check
        '''
        if offset == 0:
            if binary_value.startswith('110'):
                offset = 1
            elif binary_value.startswith('1110'):
                offset = 2
            elif binary_value.startswith('11110'):
                offset = 3
            elif binary_value.startswith('10'):
                return False
        else:
            if not binary_value.startswith('10'):
                return False
            offset -= 1

    '''
    If offset is not zero, there is an encoding error
    Else all characters are valid
    '''
    if not offset == 0:
        return False
    return True
