#!/usr/bin/python3
def minOperations(n):
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

    print(facteurs)
    return sum(facteurs)
