#pragma once
#include "tree.h"

typedef struct Node {
	Tree * tree;
	struct Node * next;
} Node;

typedef struct List {
	Node * head;
} List;

void append(List * list, Tree * tree);