#include "tree.h"
#include <stdlib.h>

Tree * create_leaf(int value)
{
	Tree * tree = malloc(sizeof(Tree));
	tree->type = leaf;
	tree->value = value;
	return tree;
}

Tree * create_branch(Tree * left, Tree * right)
{
	Tree * tree = malloc(sizeof(Tree));
	tree->type = branch;
	tree->left = left;
	tree->right = right;
	return tree;
}

void delete(Tree * tree)
{
	if (tree->type == branch)
	{
		delete(tree->left);
		delete(tree->right);
	}
	free(tree);
}