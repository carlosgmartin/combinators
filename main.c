#include <stdio.h>
#include "tree.h"
#include "list.h"
#include "eval.h"
#include "combinators.h"
#include "enum.h"

int main() {
	List list = enumerate(6); // all trees of a certain size

	int step;
	for (step = 0; step < 10; ++step)
	{
		Node * node = list.head;
		while (node != NULL) {
			Tree * tree = node->tree;
			// print(tree); printf("\n");
			printf("%d\n", get_depth(tree));
			node->tree = evaluate_once(tree);
			node = node->next;
		}
		printf("\n");
	}
	return 0;
}