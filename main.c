#include <stdio.h>
#include "tree.h"
#include "list.h"
#include "eval.h"
#include "combinators.h"

int main() {
	printf("Hello world!\n");

	/*
	Tree * K23 = create_branch(create_branch(create_leaf(K), create_leaf(0)), create_leaf(1));
	Tree * S234 = create_branch(create_branch(create_branch(create_leaf(S), create_leaf(0)), create_leaf(1)), create_leaf(2));
	List list;
	list.head = NULL;
	append(&list, K23);
	append(&list, S234);
	Node * node = list.head;
	while (node != NULL) {
		print(evaluate_once(node->tree));
		printf("\n");
		node = node->next;
	}
	*/

	Tree * tree = create_branch(create_branch(REVERSE, create_leaf(0)), create_leaf(1));
	int i = 0;
	for (i = 0; i < 10; ++i)
	{
		print(tree); printf("\n");
		tree = evaluate_once(tree);
	}


	
	

	return 0;
}