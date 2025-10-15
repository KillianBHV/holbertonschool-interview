#include "slide_line.h"
int slide_line(int *line, size_t size, int direction)
{
    if (direction == 1)
        return (to_left(line, size));
    else if (direction == 2)
        return (to_right(line, size));
    else
        return (0);
}

/**
 * to_left - Slide to the left and merge if same number
 * 
 * @line: array of integers to slide and merge
 * @size: size of the array @line
 * 
 * Return: 1 if success, otherwise 0.
 */
int to_left(int *line, size_t size)
{
    for (int *current = line; current < line + size - 1; current++)
    {
        int *next = current + 1, *moveNext = next;
        if (*current == 0)
        {
            while (*moveNext == 0 && moveNext < line + size - 1) moveNext++;

            *current = *moveNext;
            *moveNext = 0;
            moveNext = next;
        }

        if (*next == 0)
        {
            while (*moveNext == 0 && moveNext < line + size - 1) moveNext++;

            if (moveNext - next != 0)
            {
                *next = *moveNext;
                *moveNext = 0;
            }
        }
        
        if(*current == *next)
        {
            *current += *next;
            *next = 0;
        }
    }
    return (1);
}

/**
 * to_right - Slide to the right and merge if same number
 * 
 * @line: array of integers to slide and merge
 * @size: size of the array @line
 * 
 * Return: 1 if success, otherwise 0.
 */
int to_right(int *line, size_t size)
{
    for (int *current = line + size - 1; current > line; current--)
    {
        int *previous = current - 1, *movePrevious = previous;
        if (*current == 0)
        {
            while (*movePrevious == 0 && movePrevious > line) movePrevious--;

            *current = *movePrevious;
            *movePrevious = 0;
            movePrevious = previous;
        }

        if (*previous == 0)
        {
            while (*movePrevious == 0 && movePrevious > line) movePrevious--;
            if (movePrevious - previous != 0)
            {
                *previous = *movePrevious;
                *movePrevious = 0;
            }
        }
        
        if(*current == *previous)
        {
            *current += *previous;
            *previous = 0;
        }
    }
    return (1);
}
