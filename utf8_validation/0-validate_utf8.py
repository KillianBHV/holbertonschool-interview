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

        '''Bytes start and size check
        '''
        if binary_size == 1:
            if not binary_value.startswith('0'):
                return False
        elif binary_size == 2:
            if not binary_value.startswith('110'):
                return False
            else:
                offset = 8
        elif binary_size == 3:
            if not binary_value.startswith('1110'):
                return False
            else:
                offset = 16
        elif binary_size == 4:
            if not binary_value.startswith('11110'):
                return False
            else:
                offset = 24
        else:
            return False

        '''All bytes except the MSB must starts with 10 in binary
        '''
        while offset > 0:
            if not binary_value[offset:].startswith('10'):
                return False
            offset -= 8

    '''All characters are valid
    '''
    return True
