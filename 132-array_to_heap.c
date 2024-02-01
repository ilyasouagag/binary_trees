#include "binary_trees.h"

/**
 * array_to_heap - builds an array from the binary tree
 * @array: pointer to the array
 * @size: The number of element in the array.
 * Return: the pointer to the root
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int index;
	heap_t *root = NULL;

	for (index = 0; index < size; index++)
		heap_insert(&root, array[index]);

	return (root);
}
