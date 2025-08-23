#!/usr/bin/python3
"""
### MINIMUM OPERATIONS ALGORITHM ###
"""


def minOperations(n):
    """
    --- SECRET OF THE ALGORTIHM ---
    Convert prime numbers multiplication to addition
    1- Extract the prime numbers of n
    2- Return the sum of them
    """
    if not isinstance(n, int) or n < 2:
        return 0

    facteurs = []
    modulo = 2

    while not n == 1:
        if n % modulo == 0:
            facteurs.append(modulo)
            n /= modulo
        else:
            modulo += 1

    return sum(facteurs)
