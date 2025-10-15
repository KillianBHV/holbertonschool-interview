#ifndef _SLIDE_LINE_H
#define _SLIDE_LINE_H

#include <stddef.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

int slide_line(int* line, size_t size, int direction);
int to_left(int *line, size_t size);
int to_right(int *line, size_t size);

#endif /* _SLIDE_LINE_H */
