#include <stdio.h>
#include <stdlib.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stabilized_sandpile - Checks if all cells are less than or equal to 3
 * @grid: 3x3 grid to check
 * Return: 1 if grid is stable, otherwise 0
 */
int is_stabilized_sandpile(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);

	return (1);
}

/**
 * sandpiles_sum - Sums two sandpiles, then stabilize them
 * @grid1: left 3x3 grid operand
 * @grid2: right 3x3 grid operand
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (!is_stabilized_sandpile(grid1))
	{
		for (i = 0; i < 3; i++)
		{
			printf("=\n");
			print_grid(grid1);
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] <= 3)
					continue;
				if ((j - 1) != -1)
					grid1[i][j - 1] += 1;
				if ((j + 1) < 3)
					grid1[i][j + 1] += 1;
				if ((i - 1) != -1)
					grid1[i - 1][j] += 1;
				if ((i + 1) < 3)
					grid1[i + 1][j] += 1;
				grid1[i][j] -= 4;
			}
		}
		if (is_stabilized_sandpile(grid1))
			break;
	}
}
