#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of binary tree
 * @tree: pointer to the root node
 * Return: return the size of binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);
	size++;
	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);
	return (size);
}
