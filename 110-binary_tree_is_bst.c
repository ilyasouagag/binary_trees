#include "binary_trees.h"

int is_bst(const binary_tree_t *tree, int min, int max);
/**
 * is_bst - compare binary is binary search tree
 * @tree: pointer to the tree
 * @min: min int value in C
 * @max: max int value in C
 * Return: 1 if success, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (
		is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checke wether a binary tree is searchable or not
 * @tree: pointer to the tree
 * Return: 1 if success, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (isBST(tree, INT_MIN, INT_MAX));
}
