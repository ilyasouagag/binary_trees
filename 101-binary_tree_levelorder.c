#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
void print_generation(const binary_tree_t *tree, int gen, void (*func)(int));
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

/**
 * print_generation - print all element in the current level
 * @tree: pointer to thse
 * @gen: level of the tree
 * @func: pointer to a  node
 */
void print_generation(const binary_tree_t *tree, int gen, void (*func)(int))
{
	if (!tree)
		return;

	if (gen == 1)
		func(tree->n);
	else if (gen > 1)
	{
		print_generation(tree->left, gen - 1, func);
		print_generation(tree->right, gen - 1, func);
	}
}

/**
 * binary_tree_levelorder - print every level at the time
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0;
	int len = 1;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree) + 1;

	while (len <= height)
	{
		print_generation(tree, len, func);
		len++;
	}
}
