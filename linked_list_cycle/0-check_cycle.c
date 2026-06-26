#include "lists.h"

/**
 * check_cycle - Check if a singly linked list is a cycle
 * @list: The pointer to the list's head
 * Return: 0 if has no cycle, 1 if any other case
 */
int check_cycle(listint_t *list)
{
	listint_t *tortoise, *hare;

	if (list == NULL)
		return (0);

	if (list->next == NULL)
		return (0);

	tortoise = list;
	hare = list->next;

	do {
		if (tortoise == hare)
			return (1);

		tortoise = tortoise->next;

		if (hare->next != NULL)
			hare = hare->next->next;
		else
			hare = NULL;
	} while (tortoise != NULL && hare != NULL);

	return (0);
}
