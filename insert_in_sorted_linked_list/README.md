# INSERT IN SORTED LINKED LIST

## Purpose
Insert an element in a sorted singly linked list

NOTA: Start list is supposed already sorted

- Method Type: **`Iterative`**
- Libraries: **`stdio.h`**, **`stdlib.h`**, **`stdio.h`**, **`time.h`** (for tests only)

## Compilation
```bash
holbie@VM-Algos:~/insert_in_sorted_linked_list$ gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert 
```

## Execution Process (Output)
```bash
holbie@VM-Algos:~/insert_in_sorted_linked_list$ cat 0-main.c
# --- SNIPPET: Random Generated Values ---
[...]
{
	[...]
	for (i = 0; i < 5; i++)
	{
		j = rand() % 300 + 1;
		k = rand() % 2;

		if (k % 2 == 0)
			insert_node(&head, j);
		else
			insert_node(&head, -1*j);
	}
	[...]
}
holbie@VM-Algos:~/insert_in_sorted_linked_list$
```

```bash
holbie@VM-Algos:~/insert_in_sorted_linked_list$ ./insert
# --- NOTA ---
# 27 is supposed insert manually
# -96, 23, 64, 962, 1026 are supposed generated
0
1
2
3
4
98
402
1024
-------------------
-96
0
1
2
3
4
23
27
64
98
402
962
1024
1026
holbie@VM-Algos:~/insert_in_sorted_linked_list$
```
