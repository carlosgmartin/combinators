#include "enum.h"
#include "list.h"
#include "tree.h"
#include <stdio.h>

List enumerate(int size)
{
	List list;
	list.head = NULL;
	if (size == 0) {
		append(&list, create_leaf(K));
		append(&list, create_leaf(S));
	}
	int weight;
	for (weight = 0; weight < size; ++weight) {
		List left_trees = enumerate(weight);
		List right_trees = enumerate(size - 1 - weight);

		Node * left_tree_node = left_trees.head;
		while (left_tree_node != NULL) {
			Tree * left_tree = left_tree_node->tree;
			Node * right_tree_node = right_trees.head;
			while (right_tree_node != NULL) {
				Tree * right_tree = right_tree_node->tree;
				append(&list, create_branch(left_tree, right_tree));
				right_tree_node = right_tree_node->next;
			}
			left_tree_node = left_tree_node->next;
		}
	}
	return list;
}