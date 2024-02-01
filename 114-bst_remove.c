#include "binary_trees.h"
bst_t *minimum_finder(bst_t *tree);
/**
 * minimum_finder - Finds the minimum root
 * @root: pointer to the tree
 * Return: the min number
 */
bst_t *minimum_finder(bst_t *tree)
{
	while (tree->left != NULL)
		tree = tree->left;
	return (tree);
}

/**
 * bst_remove - remove a node from a searchable binary tree
 * @root: pointer to the root
 * @value: value to remove in the tree
 * Return: pointer to the node deleted
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *parent;

	if (!root)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			root = NULL;
		}
		else if (!root->left)
		{
			temp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(temp);
		}
		else if (!root->right)
		{
			temp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(temp);
		}
		else
		{
			temp = min_finder(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}
