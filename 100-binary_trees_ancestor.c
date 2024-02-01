#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor
 * @first:  first node
 * @second: second node
 * Return: return a pointer to the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *prev1, *prev2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	prev1 = first->parent;
	prev2 = second->parent;
	if (first == prev2 || !prev1 || (!prev1->parent && prev2))
		return (binary_trees_ancestor(first, prev2));
	else if (second == prev1 || !prev2 || (!prev2->parent && prev1))
		return (binary_trees_ancestor(prev1, second));
	return (binary_trees_ancestor(prev1, prev2));
}
