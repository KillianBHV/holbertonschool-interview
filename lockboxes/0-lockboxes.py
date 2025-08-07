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
    box_size = len(boxes)
    box_index_list = []
    box_valid_list = []

    for i in range(box_size):
        box_index_list.append(i)
        box_valid_list.append([i, False])
    box_valid_list[0][1] = True

    for i in range(box_size):
        if len(boxes[i]) == 0:
            box_index_list[i] = -1
            box_valid_list[i][1] = True
        else:
            if box_valid_list[i][1]:
                box_index_list[i] = -1

            for j in range(len(boxes[i])):
                if not 0 <= boxes[i][j] < box_size:
                    boxes[i][j] = -1

    for i in range(box_size):
        if box_valid_list[i][1]:
            for j in range(len(boxes[i])):
                if not boxes[i][j] < 0:
                    box_valid_list[boxes[i][j]][1] = True
                    box_index_list[boxes[i][j]] = -4

    back_values_search = []
    for i in range(box_size):
        if box_valid_list[i][1]:
            for j in range(len(boxes[i])):
                if not boxes[i][j] < 0:
                    back_values_search.append(boxes[i][j])

    back_values_search = list(set(back_values_search))
    for i in range(len(boxes)):
        if i in back_values_search:
            box_valid_list[i][1] = True

    for i in range(len(box_valid_list)):
        box_valid_list[i] = box_valid_list[i][1]

    return all(box_valid_list)
