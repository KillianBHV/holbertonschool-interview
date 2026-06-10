#!/usr/bin/python3


"""
    You have only two operation allowed: Copy All and Paste
    Objective: Be as much efficient as possible
"""


def minOperations(n: int) -> int:
    """Get the minimum actions required

    Args:
        n: number of H desired

    Returns:
        Number of required iterations
    """
    if not isinstance(n, int) or n < 2:
        return 0
    elif n == 2:
        return 2

    # Prime factors
    search_prime = []
    div = 2

    while div * div <= n:
        if n % div == 0:
            search_prime.append(div)
            n //= div
        else:
            div += 1
    search_prime.append(n)

    return sum(search_prime)
