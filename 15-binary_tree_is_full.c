#include "binary_trees.h"

int is_full_recursive(const binary_tree_t *tree);
/**
 * binary_tree_is_full - check if the binary tree is full
 * @tree: root node of the binary tree
 * Return: 0 or 1 if it is full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}

/**
 * is_full_recursive - check if a node is a leaf
 * @tree: root node of the binary tree
 * Return: 0 or 1 it is a leaf
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
			(tree->left == NULL && tree->right != NULL) ||
			is_full_recursive(tree->left) == 0 ||
			is_full_recursive(tree->right) == 0)

			return (0);
	}

	return (1);
}