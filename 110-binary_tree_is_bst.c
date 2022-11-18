#include "binary_trees.h"

int bts_recur(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bts_recur(tree, INT_MIN, INT_MAX));
}

/**
 * bts_recur - checks if a binary tree is a valid BST recursively
 * @tree: a pointer to the root node of the tree to check
 * @min: Lower bound of checked nodes
 * @max: Upper bound of checked nodes
 * Return: 1 if valid BST, 0 otherwise
 */
int bts_recur(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bts_recur(tree->left, min, tree->n - 1) &&
			bts_recur(tree->right, tree->n + 1, max));
}

