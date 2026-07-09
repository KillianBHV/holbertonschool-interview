# PALINDROME INTEGER

## Purpose
Checks if a provided integer forms a palindrome or not

NOTA: A larger better way exists, but I have chosen the successive ten power divisions method

- Method Type: **`Iterative`**
- Libraries: **`stdio.h`**, **`stdlib.h`**

## Compilation
```bash
holbie@VM-Algos:~/palindrome_integer$ gcc -Wall -Werror -Wextra -pedantic -g3 0-main.c 0-is_palindrome.c -o palindrome
```

## Execution Process (Output)
```bash
holbie@VM-Algos:~/palindrome$ ./palindrome 12345678987654321
Linked list is a palindrome

holbie@VM-Algos:~/palindrome$ ./palindrome 1431
Linked list is not a palindrome

holbie@VM-Algos:~/palindrome$ ./palindrome 13531
Linked list is a palindrome

holbie@VM-Algos:~/palindrome$ ./palindrome 136731
Linked list is not a palindrome

holbie@VM-Algos:~/linked_lists_palindrome$
```
