#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a new node at a specified place of a listint_t list
 * @head: pointer to pointer of first node of listint_t
 * @number: integer to be included in the new node
 *
 * Return: address of the new node or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;
	listint_t *nextNode;

	current = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		nextNode = current;
		while (nextNode->next != NULL && nextNode->n < number)
			nextNode = nextNode->next;
	
		while (current->next != nextNode && current->next != NULL)
			current = current->next;

		if (current != nextNode)
		{
			if (new->n < nextNode->n)
			{
				current->next = new;
				new->next = nextNode;
			}
			else
				nextNode->next = new;
		}
		else
		{
			if (new->n > nextNode->n)
				current->next = new;
			else
			{
				new->next = current;
				current->next = NULL;
				*head = new;
			}
		}
	}
	
	return (new);
}
