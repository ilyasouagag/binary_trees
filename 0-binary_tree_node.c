#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent of the node
 * @value: value to put in the node
 * Return: return a pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *root;

	root = malloc(sizeof(binary_tree_t));
	if (!root)
		return (NULL);
	root->n = value;
	root->left = NULL;
	root->right = NULL;
	root->parent = parent;
	return (root);
}
