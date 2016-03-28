#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

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

void print(Tree * tree)
{
	switch (tree->type)
	{
		case leaf:
			switch (tree->value)
			{
				case K:
					printf("K");
					break;
				case S:
					printf("S");
					break;
				default:
					printf("%d", tree->value);
					break;
			}
			break;
		case branch:
			printf("(");
			print(tree->left);
			printf(", ");
			print(tree->right);
			printf(")");
			break;
	}
}

int equals(Tree * a, Tree * b) {
	if (a->type == b->type == leaf)
	{
		return a->value == b->value;
	}
	else if (a->type == b->type == branch)
	{
		return equals(a->left, b->left) && equals(a->right, b->right);
	}
	else
	{
		return 0;
	}
}