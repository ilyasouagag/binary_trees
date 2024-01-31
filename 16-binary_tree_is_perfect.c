#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree);
int prefect_checker(const binary_tree_t *tree,
					size_t leaf_depth, size_t generation);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
size_t depth(const binary_tree_t *tree);
/**
 * binary_tree_is_perfect - check if the binary tree is perfect
 * @tree: root node of the binary tree
 * Return: 0 or 1 if it is perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (prefect_checker(tree, depth(get_leaf(tree)), 0));
}
/**
 * prefect_checker - check if the binary tree is perfect
 * @tree: root node of the binary tree
 * @leaf_depth: depth of the leaf
 * @generation: the generation of the node
 * Return: 0 or 1 if it is perfect
 */
int prefect_checker(const binary_tree_t *tree,
					size_t leaf_depth, size_t generation)
{
	if (!tree->left && !tree->right)
		return (generation == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (prefect_checker(tree->left, leaf_depth, generation + 1) &&
			prefect_checker(tree->right, leaf_depth, generation + 1));
}

/**
 * depth - calculates the depth of a node
 * @tree: root node of the binary tree
 * Return: the depth of the node
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - get leaf of the tree
 * @tree: root node of the binary tree
 * Return: pointer to the leaf
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}
