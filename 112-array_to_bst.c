#include "binary_trees.h"
/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: A pointer to the first element of the array
 * @size: The number of element in the array
 *
 * Return: A pointer to the root node
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (bst_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
