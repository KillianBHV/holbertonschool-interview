#!/usr/bin/python3
"""
SCRIPT 0 - LOCKBOXES ALGORITHM
"""


def canUnlockAll(boxes):
    """
    Return if all the boxes can be unlocked
    """
    digitFound = []
    for i in range(len(boxes)):
        digitFound.append(False)

    for box in range(len(boxes)):
        for element in range(len(boxes[box])):
            if boxes[box][element] in boxes[box]:
                digitFound[box] = True
                break

    return all(digitFound)
