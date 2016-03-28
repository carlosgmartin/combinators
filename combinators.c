#include <stdio.h>
#include <stdlib.h>

typedef enum { leaf, branch } Type;
typedef struct Tree {
	Type type;
	union {
		int value;
		struct {
			struct Tree * left;
			struct Tree * right;
		};
	};
} Tree;

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

Tree * delete(Tree * tree)
{
	if (tree->type == branch)
	{
		delete(tree->left);
		delete(tree->right);
	}
	free(tree);
}

int main() {
	printf("Hello world!\n");
	return 0;
}