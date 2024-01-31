#include "binary_trees.h"

int binary_tree_leaf_checker(binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
/**
 * binary_tree_is_full - check if the binary tree is full
 * @tree: root node of the binary tree
 * Return: 0 or 1 if it is full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_leaf_checker(tree));
}

/**
 * binary_tree_leaf_checker - check if a node is a leaf
 * @tree: root node of the binary tree
 * Return: 0 or 1 it is a leaf
 */
int binary_tree_leaf_checker(binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
			(tree->left == NULL && tree->right != NULL) ||
			binary_tree_leaf_checker(tree->left) == 0 ||
			binary_tree_leaf_checker(tree->right) == 0)
			return (0);
	}
	return (1);
}
