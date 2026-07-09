#include "palindrome.h"

/**
 * is_palindrome - Checks if an integer is a palindrome
 *
 * @n: num to test for palindrome
 *
 * Return: 1 if @n is an effective palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	/* One-digit only number is automatically considered as palindrome */
	if (n < 10)
		return (1);

	unsigned long revertValue, i, value;
	unsigned long currentSize = 1, power = 0;

	/* Get the highest power of 10 */
	revertValue = n;
	while (revertValue >= 10)
	{
		power++;
		revertValue /= 10;
	}

	revertValue = 0;
	for (i = power; i > 0; i--)
		currentSize *= 10;

	/* Successive digits enumeration */
	value = n;
	for (i = 0; i < power; i++)
	{
		revertValue += (value % 10) * currentSize;
		currentSize /= 10;
		value /= 10;
	}
	revertValue	+= value;

	/* Final Result */
	if (revertValue == n)
		return (1);
	return (0);
}
