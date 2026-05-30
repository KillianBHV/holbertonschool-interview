#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current, *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	current = *head;
	while (current->next != NULL && current->next->n < number)
		current = current->next;

	if (current == *head && number < current->n)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		if (current->next != NULL)
			new->next = current->next;
		current->next = new;
	}

	return (new);
}
