#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 on failure
 */

int heap_extract(heap_t **root)
{
	int value;
	heap_t *node;

	if (root == NULL || *root == NULL)
		return (0);
	value = (*root)->n;
	node = *root;
	while (node->left != NULL || node->right != NULL)
	{
		if (node->right == NULL || node->left->n > node->right->n)
		{
			node->n = node->left->n;
			node = node->left;
		}
		else
		{
			node->n = node->right->n;
			node = node->right;
		}
	}
	if (node->parent != NULL)
	{
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
	}
	else
		*root = NULL;
	free(node);
	return (value);
}