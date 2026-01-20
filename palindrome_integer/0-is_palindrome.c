#include "palindrome.h"

/**
 * is_palindrome - Checks with calculs if a number is a palindrome
 *
 * @n: number to check
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned int _n = n;
	unsigned int numHighUnit = 0;
	unsigned int resultat = 0;
	unsigned int operand = 1;

	/**
	 * STEP 1: Search the highest pow of the number
	 */
	while (_n >= 10)
	{
		numHighUnit++;
		_n /= 10;
	}
	_n = n;

	for (unsigned int i = 0; i < numHighUnit; i++)
		operand *= 10;

	/**
	 * STEP 2: Build a new number with modulus of each pow level
	 */
	for (unsigned int i = numHighUnit; i > 0; i--)
	{
		resultat += ((n % 10) * operand);
		operand /= 10;
		n /= 10;
	}
	resultat += n;

	/**
	 * Compares the final result with the original number
	 */
	if (resultat == _n)
		return (1);
	return (0);
}

