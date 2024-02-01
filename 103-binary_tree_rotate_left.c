#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node
 * Return: return a pointer to the new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	root = tree->right;
	tree->right = root->left;

	if (root->left != NULL)
		root->left->parent = tree;

	root->left = tree;
	root->parent = tree->parent;
	tree->parent = root;

	if (root->parent != NULL)
	{
		if (root->parent->left == tree)
			root->parent->left = root;
		else
			root->parent->right = root;
	}

	return (root);
}
