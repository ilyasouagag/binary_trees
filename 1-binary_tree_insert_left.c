#include "binary_trees.h"
/**
 *
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *other;

    if (parent == NULL)
        return NULL;
    other = binary_tree_node(parent, value);
    if (other == NULL)
        return NULL;
    if (!parent->left)
        parent->left = other;
    else
    {
        other->left = parent->left;
        parent->left->parent = other;
        parent->left = other;
    }
    return (parent);
}
