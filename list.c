#include "list.h"
#include <stdlib.h>

void append(List * list, Tree * tree) {
	Node * node = malloc(sizeof(Node));
	node->tree = tree;
	node->next = list->head;
	list->head = node;
}