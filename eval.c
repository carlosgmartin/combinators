#include "eval.h"

Tree * evaluate_once(Tree * tree)
{
	if (tree->type == branch && 
		tree->left->type == branch && 
		tree->left->left->type == leaf &&
		tree->left->left->value == K)
	{
		return tree->left->right; // Reduce to normal form
	}
	else if (tree->type == branch &&
		tree->left->type == branch &&
		tree->left->left->type == branch &&
		tree->left->left->left->type == leaf &&
		tree->left->left->left->value == S)
	{
		Tree * x = tree->left->left->right;
		Tree * y = tree->left->right;
		Tree * z = tree->right;
		return create_branch(create_branch(x, z), create_branch(y, z)); // Reduce to normal form
	}
	else
	{
		if (tree->type == branch)
		{
			return create_branch(evaluate_once(tree->left), evaluate_once(tree->right));
		}
		else
		{
			return tree;
		}
	}
}

Tree * evaluate_full(Tree * tree)
{
	if (tree->type == branch && 
		tree->left->type == branch && 
		tree->left->left->type == leaf &&
		tree->left->left->value == K)
	{
		return evaluate_full(tree->left->right); // Reduce to normal form
	}
	else if (tree->type == branch &&
		tree->left->type == branch &&
		tree->left->left->type == branch &&
		tree->left->left->left->type == leaf &&
		tree->left->left->left->value == S)
	{
		Tree * x = tree->left->left->right;
		Tree * y = tree->left->right;
		Tree * z = tree->right;
		return evaluate_full(create_branch(create_branch(x, z), create_branch(y, z))); // Reduce to normal form
	}
	else
	{
		if (tree->type == branch)
		{
			return create_branch(evaluate_full(tree->left), evaluate_full(tree->right));
		}
		else
		{
			return tree;
		}
	}
}