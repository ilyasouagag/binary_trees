#include "binary_trees.h"
/**
 * binary_tree_balance - checks the balance of binary tree
 * @tree: root node of the binary tree
 * Return: the difference in size between left and right
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int count_1 = 0;
	int count_2 = 0;

	if (!tree)
		return (0);

	if (tree->left)
		count_1 = binary_tree_height(tree->right);

	if (tree->right)
		count_2 = binary_tree_height(tree->left);

	return (count_1 - count_2);
}
