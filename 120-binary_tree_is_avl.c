#include "binary_trees.h"

int bt_is_avl_recur(const binary_tree_t *tree, int min, int max);
size_t bt_height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree:  pointer to the root node of the tree to check
 * Return: 1 if valid AVL, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bt_is_avl_recur(tree, INT_MIN, INT_MAX));
}

/**
 * bt_is_avl_recur - helper that finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if tree is valid avl, 0 otherwise
 */
int bt_is_avl_recur(const binary_tree_t *tree, int min, int max)
{
	int left_path_height, right_path_height;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	left_path_height = tree->left ? 1 + bt_height(tree->left) : 0;
	right_path_height = tree->right ? 1 + bt_height(tree->right) : 0;
	if (abs(left_path_height - right_path_height) > 1)
		return (0);
	return (bt_is_avl_recur(tree->left, min, tree->n - 1) &&
			bt_is_avl_recur(tree->right, tree->n + 1, max));
}

/**
 * bt_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 * Return: height of the tree, otherwise 0
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);
	left_height = tree->left ? 1 + bt_height(tree->left) : 0;
	right_height = tree->right ? 1 + bt_height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}
