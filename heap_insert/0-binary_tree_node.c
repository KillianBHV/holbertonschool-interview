#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - append a node to a parent
 *
 * @parent: Pointer to the parent of the node
 * @value: integer to store
 *
 * Return: Pointer to the created node or NULL if failed
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = NULL;
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	parent = node;

	return (node);
}
