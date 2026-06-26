#include "binary_trees.h"


/**
 * height_ - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
size_t height_(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + height_(tree->left) : 0;
	height_r = tree->right ? 1 + height_(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * sort_heap - Sorting the heap
 * @node: The new node
 * @value: The value
 * Return: Pointer to the new position
 */
heap_t *sort_heap(heap_t *node, int value)
{
	while (node->parent != NULL && node->parent->n < value)
	{
		node->n = node->parent->n;
		node->parent->n = value;
		node = node->parent;
	}
	return (node);
}

/**
 * find_next - Finds the next availale position in the tree
 * @root: The root node of the tree at this point
 * @height: The height limit
 * @value: The payload
 * Return: The pointer to the parent node
 */
heap_t *find_next(heap_t *root, size_t height, int value)
{
	heap_t *l_node = NULL, *r_node = NULL;

	if (height == 0 || height == 1)
	{
		if (root->left == NULL)
		{	root->left = binary_tree_node(root, value);
			return (sort_heap(root->left, value));
		}
		else if (root->right == NULL)
		{	root->right = binary_tree_node(root, value);
			return (sort_heap(root->right, value));
		}
		else
			return (NULL);
	}

	l_node = find_next(root->left, (height - 1), value);
	if (l_node == NULL)
		r_node = find_next(root->right, (height - 1), value);
	return (l_node != NULL ? l_node : r_node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: The main node of the tree at this point
 * @value: The payload
 * Return: The pointer to the node or NULL if failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t h = 0; /* Tree height */
	heap_t *l_node = NULL, *r_node = NULL;

	/* If the root node is doesn't exist yet */
	if (*root == NULL)
	{	*root = binary_tree_node(NULL, value);
		return (*root);
	}
	/* If only root, else get the height */
	if ((*root)->left == NULL)
	{	(*root)->left = binary_tree_node(*root, value);
		if (value > (*root)->n)
		{	(*root)->left->n = (*root)->n, (*root)->n = value;
			return (*root);
		}
		return ((*root)->left);
	}
	else if ((*root)->right == NULL)
	{	(*root)->right = binary_tree_node(*root, value);
		if (value > (*root)->n)
		{	(*root)->right->n = (*root)->n, (*root)->n = value;
			return (*root);
		}
		return ((*root)->right);
	}
	else
		h = height_(*root);
	/* Go for the next available position in the height */
	l_node = find_next((*root)->left, (h - 1), value);
	if (l_node == NULL)
		r_node = find_next((*root)->right, (h - 1), value);
	if (l_node == NULL && r_node == NULL)
		l_node = find_next((*root)->left, h, value);
	return (l_node != NULL ? l_node : r_node);
}
