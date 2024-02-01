#include "binary_trees.h"
size_t binary_tree_size(const binary_tree_t *tree);
int is_complete(binary_tree_t *tree, int index, int size);

/**
 * binary_tree_size - measures the size of binary tree
 * @tree: pointer to the root node
 * Return: return the size of binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);
	size++;
	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);
	return (size);
}

/**
 * is_complete - check if tree is complete
 * @tree: Pointer to tree
 * @index: Index of the node been evaluated
 * @size: size of binary tree
 *
 * Return: 1 if the tree is a heap, 0 otherwise
 */

int is_complete(binary_tree_t *tree, int index, int size)
{
	if (!tree)
		return (0);

	if (index >= size)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->right && !tree->left)
		return (0);
	if (tree->left && !tree->right)
		return (is_complete(tree->left, index * 2 + 1, size));

	return (is_complete(tree->left, index * 2 + 1, size) &&
			is_complete(tree->right, index * 2 + 2, size));
}

/**
 * binary_tree_is_complete - check if a tree is complete
 * @tree: Pointer to root
 * Return: 1 if complete 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes;
	binary_tree_t *root;

	if (!tree)
		return (0);

	root = (binary_tree_t *)tree;
	nodes = binary_tree_size(root);

	return (is_complete(root, 0, nodes));
}
