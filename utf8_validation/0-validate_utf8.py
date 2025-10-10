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
        if not 1 <= binary_size <= 4:
            return False

        if binary_size == 2 and not binary_value[-8:].startswith('110'):
            return False
        elif binary_size == 3 and not binary_value[-8:].startswith('1110'):
            return False
        elif binary_size == 4 and not binary_value[-8:].startswith('11110'):
            return False
        elif binary_value == 1 and binary_value.startswith('10'):
            return False

    '''All characters are valid
    '''
    return True
