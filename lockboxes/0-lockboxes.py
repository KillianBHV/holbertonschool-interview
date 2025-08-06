#!/usr/bin/python3
"""
SCRIPT 0 - LOCKBOXES ALGORITHM
"""


def canUnlockAll(boxes):
    """
    Return if all the boxes can be unlocked
    An empty packet of boxes is automatically unlocked

    :param boxes: boxes to pass through
    :return: is all digitFound
    """
    if len(boxes) == 0:
        return True

    digitFound = []
    for i in range(len(boxes)):
        if len(boxes[i]) == 0:
            digitFound.append(True)
        else:
            digitFound.append(False)
    digitFound[0] = True

    for i in range(len(boxes)):
        if len(boxes[i]) == 0:
            digitFound[i] = True
            continue

        if digitFound[i]:
            for j in range(len(boxes[i])): 
                if 0 <= boxes[i][j] <= len(boxes):
                    digitFound[boxes[i][j]] = True

    researchIndex = []
    for i in range(len(boxes)):
        if digitFound[i]:
            researchIndex.extend(boxes[i])
    """ [OPTIONAL] We remove all duplicate values
    """
    researchIndex = list(set(researchIndex))

    for i in range(len(boxes)):
        if not digitFound[i]:
            for j in range(len(boxes[i])):
                if boxes[i][j] in researchIndex:
                    digitFound[i] = True
                    break

    return all(digitFound)
