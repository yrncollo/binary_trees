#include "binary_trees.h"

/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * delete_node - deletes a node from a binary search tree.
 * @root: pointer to the root node of the BST.
 * @node: pointer to the node to delete from the BST.
 * Return: pointer to the new root node after deletion.
 */
bst_t *delete_node(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (delete_node(root, successor));
}

/**
 * bst_remove_recur - removes a node from a binary search tree recursively.
 * @root: pointer to the root node of the BST to remove a node from.
 * @node: pointer to the current node in the BST.
 * @value: value to remove from the BST.
 * Return: pointer to the root node after deletion.
 */
bst_t *bst_remove_recur(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (delete_node(root, node));
		if (node->n > value)
			return (bst_remove_recur(root, node->left, value));
		return (bst_remove_recur(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - removes a node from a binary search tree.
 * @root: pointer to the root node of the BST to remove a node from.
 * @value: value to remove in the BST.
 * Return: A pointer to the new root node after deletion.
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recur(root, root, value));
}
