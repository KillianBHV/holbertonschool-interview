#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Max Binary Heap Insertion
 *
 * @root: Pointer to pointer to the root node of the heap
 * @value: Value to be inserted
 *
 * Return: Tree with max heap ordering
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	heap_t *parent;

	if (*root == NULL)
	{
		node = binary_tree_node(*root, value);
		*root = node;
		return (*root);
	}
	node = *root;

	while (node != NULL)
	{
		parent = node;
		if (node->n == value)
			return (swap(node));

		if (value > node->n)
			node = parent->left;
		else
			node = parent->right;
	}

	if (value > parent->n)
	{
		parent->left = binary_tree_node(parent, value);
		return (parent->left);
	}
	else
	{
		parent->right = binary_tree_node(parent, value);
		return (parent->right);
	}
}

/**
 * swap - Swaps current node with larger node
 *
 * @node: Pointer to current node
 *
 * Return: A new node
 */
heap_t *swap(heap_t *node)
{
	while (node && node->parent)
	{
		while (node->n > node->parent->n)
		{
			node = node->parent;
			node->n += node->parent->n;
			node->parent->n -= node->n;
			node->parent->n = node->n - node->parent->n;
		}
	}

	return (node);
}
