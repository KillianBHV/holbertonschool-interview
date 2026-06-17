#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - Checks if list chains a palindrome
 * @head: points to the first node of a listint_t list
 * Return: 1 if it is a palindrome, otherwise 0.
 */
int is_palindrome(listint_t **head)
{
	if (*head == NULL)
		return (0);

	listint_t *left;
	listint_t *right;
	unsigned int n;

	n = 0;
	left = *head;
	while (left->next != NULL)
	{
		n++;
		left = left->next;
	}

	for (int i = n; i >= 0; i--)
	{
		left = *head;
		right = *head;

		for (int j = (n - i); j > 0; j--)
			left = left->next;
		for (int j = i; j > 0; j--)
			right = right->next;

		if (left->n != right->n)
			return (0);

		if (left->next == right || left->next == right->next)
			break;
	}

	return (1);
}
