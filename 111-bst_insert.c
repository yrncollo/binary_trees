#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: created node or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp, *temp1, *new_node;

	temp = temp1 = new_node = NULL;
	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	temp = *tree;
	while (temp)
	{
		temp1 = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}

	new_node = binary_tree_node(NULL, value);
	if (temp1 == NULL)
		temp1 = new_node;
	else if (value < temp1->n)
	{
		temp1->left = new_node;
		new_node->parent = temp1;
	}
	else
	{
		temp1->right = new_node;
		new_node->parent = temp1;
	}

	return (new_node);
}
