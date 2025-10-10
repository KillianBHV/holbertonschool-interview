#!/usr/bin/python3
"""Define a method to validate UTF8 encoding
"""


def validUTF8(d):
    """Return a True statement for a valid utf8 encoding else return False
    """
    if not type(d) is list:
        return False

    for i in d:
        if not type(i) is int or not 0 <= i <= 255:
            return False

    return True
