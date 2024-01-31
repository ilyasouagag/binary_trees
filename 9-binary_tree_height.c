#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of binary tree
 * @tree: pointer to the root node
 * Return: return the height of binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t count_1 = 0;
	size_t count_2 = 0;

	if (!tree)
		return (0);

	if (tree->left)
		count_1 = 1 + binary_tree_height(tree->right);

	if (tree->right)
		count_2 = 1 + binary_tree_height(tree->left);

	if (count_1 > count_2)
		return (count_1);
	return (count_2);
}
