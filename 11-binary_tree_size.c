#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: 0 if NULL or size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);
	size = binary_tree_size(tree->left) + 1;
	size += binary_tree_size(tree->right);
	return (size);
}
