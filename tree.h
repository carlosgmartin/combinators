#pragma once
enum { K = -2, S };

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

Tree * create_leaf(int value);

Tree * create_branch(Tree * left, Tree * right);

void delete(Tree * tree);

void print(Tree * tree);

int equals(Tree * a, Tree * b);

int get_size(Tree * tree);

int get_depth(Tree * tree);