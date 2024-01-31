#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the
 * right-child of another node
 * @parent: parent of the node
 * @value: value to put in the node
 * Return: return a pointer to the new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *other;

	if (parent == NULL)
		return (NULL);
	other = binary_tree_node(parent, value);
	if (!other)
		return (NULL);
	if (!parent->right)
		parent->right = other;
	else
	{
		other->right = parent->right;
		parent->right->parent = other;
		parent->right = other;
	}
	return (parent);
}
