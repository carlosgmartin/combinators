#include <stdio.h>
#include "tree.h"
#include "list.h"

int main() {
	printf("Hello world!\n");

	Tree * K23 = create_branch(create_branch(create_leaf(K), create_leaf(0)), create_leaf(1));
	Tree * S234 = create_branch(create_branch(create_branch(create_leaf(S), create_leaf(0)), create_leaf(1)), create_leaf(2));

	List list;
	list.head = NULL;
	append(&list, K23);
	append(&list, S234);

	Node * node = list.head;
	while (node != NULL) {
		print(node->tree);
		printf("\n");
		node = node->next;
	}

	return 0;
}