#include <stdio.h>
#include "tree.h"

int main() {
	printf("Hello world!\n");

	Tree * tree = create_branch(create_branch(create_leaf(S), create_leaf(2)), create_branch(create_leaf(3), create_leaf(4)));
	print(tree);

	return 0;
}