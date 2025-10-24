#include "palindrome.h"
/**
 * is_palindrome - checks if a number is a palindrome
 *
 * @n: number to be checked
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long modulo_ref = n;
	unsigned long modulo_iteratif = 0;

	while (modulo_ref != 0)
	{
		modulo_iteratif *= 10;
		modulo_iteratif = modulo_iteratif + modulo_ref % 10;
		modulo_ref /= 10;
	}

	if (modulo_ref == modulo_iteratif)
		return (1);
	return (0);
}

