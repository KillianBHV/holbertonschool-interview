#include "menger.h"

/**
 * menger - Prints 2D Menger
 *
 * @level: level to reach
 *
 * Return: Nothing
 */
void menger(int level)
{
	int x, y, n, m, i;
	char c;

	m = pow(3, level);
	for (n = 0; n < m; n++)
	{
		for (i = 0; i < m;)
		{
			c = '#';
			x = n;
			y = i++;

			while (y > 0 || x > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
					c = ' ';
				x /= 3;
				y /= 3;
			}
			printf("%c", c);
		}
		printf("\n");
	}
}

