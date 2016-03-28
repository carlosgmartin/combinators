#include <stdio.h>

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

int main() {
	printf("Hello world!\n");
	return 0;
}