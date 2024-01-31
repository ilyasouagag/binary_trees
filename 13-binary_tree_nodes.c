#include "binary_trees.h"
/**
 * binary_tree_nodes - count nodes with children
 * @tree: root node of the binary tree
 * Return: the numbder nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	if (tree->left || tree->right)
		count = 1;

	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	return (count);
}
