#!/usr/bin/python3
def canUnlockAll(boxes):
    digitFound = []
    for i in range(len(boxes)):
        digitFound.append(False)

    for box in range(len(boxes)):
        for element in range(len(boxes[box])):
            if boxes[box][element] in boxes[box]:
                digitFound[box] = True
                break

    return all(digitFound)
