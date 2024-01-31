#include "binary_trees.h"
/**
 * binary_tree_leaves - measures the leaves of binary tree
 * @tree: pointer to the root node
 * Return: return the leaves of binary tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leave = 0;

	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		leave++;

	leave += binary_tree_leaves(tree->left);
	leave += binary_tree_leaves(tree->right);
	return (leave);
}
