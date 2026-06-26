#include "binary_trees.h"

/**
 * binary_tree_node - Adding a node to the binary tree
 * @parent: The parent node
 * @value: The payload
 * Return: Pinter to the new node or NULL if failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	heap_t *node;

	node = malloc(sizeof(heap_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
