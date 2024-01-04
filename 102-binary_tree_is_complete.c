#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int nodes_count = 1;
	int index = 0;
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (!queue)
		return (0);

	queue[0] = (binary_tree_t *)tree;

	while (index < nodes_count)
	{
		binary_tree_t *current = queue[index++];

		if (current->left)
		{
			queue[nodes_count++] = current->left;
		}
		else if (current->right)
		{
		free(queue);
		return (0);
		}

		if (current->right)
		{
			queue[nodes_count++] = current->right;
		}
		else if (index != nodes_count - 1)
		{
		free(queue);
		return (0);
		}
	}
	free(queue);
	return (1);
}
