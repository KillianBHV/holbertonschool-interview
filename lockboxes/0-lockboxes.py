#!/usr/bin/python3


"""Checks boxes to check if we can open them all
"""


def canUnlockAll(boxes: list[list]) -> bool:
    """Determines if all boxes can be opened

    Args:
        boxes: all boxes with their keys

    Returns:
        True or False
    """
    # ENTRY POINT TYPE CHECK
    # Returns immediately False if not satisfied
    if not (
        isinstance(boxes, list)
        and all(isinstance(x, list) for x in boxes)
    ):
        return False

    # CASE 1: There is no box
    # CASE 2: The is one box only
    number_of_boxes = len(boxes)
    if number_of_boxes == 1:
        return True

    # MASTER CASE
    # Key Initialisation
    max_value = 0

    for box in boxes:
        for val in box:
            if val > max_value:
                max_value = val

    keys = []
    for i in range(number_of_boxes):
        keys.append(False)

    # First Box Keys
    for key in boxes[0]:
        keys[0] = True

    # Other Boxes
    # PS - WARNING: First loop is non-removable
    for i in range(number_of_boxes):
        for box in range(number_of_boxes):
            for key in boxes[box]:
                if keys[box] and key < number_of_boxes:
                    keys[key] = True

        if all(keys):
            return True

    return all(keys)
