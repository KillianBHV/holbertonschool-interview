#include <stdio.h>
#include "lists.h"

/**
 * update_half_of_list - Get the first value of a second half listint_t list
 * @head: points to the first node of a listint_t list
 * Return: 1 if it is a palindrome, otherwise 0.
 */
listint_t *update_half_of_list(listint_t **head, const int hf_nb_nodes)
{
	listint_t *start;
	listint_t *current = NULL;
	int n;

	start = *head;

	for (int i = 0; i < hf_nb_nodes; i++)
	{
		current = start;
		
		for (int j = i; j < hf_nb_nodes; j++)
		{
			n = current->n;
			current->n = start->n;
			start->n = n;
			current = current->next;
		}
		start = start->next;
	}

	return current;
}

/**
 * is_palindrome - Checks if list chains a palindrome
 * @head: points to the first node of a listint_t list
 * Return: 1 if it is a palindrome, otherwise 0.
 */
int is_palindrome(listint_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return (1);
	
	listint_t *start = *head;
	listint_t *current = NULL;
	int node_index = 1;
	int is_odd = 0;

	while (start->next != NULL)
	{
		start = start->next;
		node_index++;
	}

	start = *head;
	if (node_index % 2 == 1)
		is_odd = 1;

	node_index /= 2;
	current = update_half_of_list(head, node_index);

	if (is_odd)
		current = current->next;

	while (current->next != NULL)
	{
		if (start->n != current->n)
			return (0);

		start = start->next;
		current = current->next;
	}

	return (1);
}
