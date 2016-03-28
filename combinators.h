#include "tree.h"



// Identity combinator
// I x y = x y
#define IDENTITY create_branch(create_branch(create_leaf(S), create_leaf(K)), create_leaf(K));

// Recursion combinator
// R a = I a (I a) = a a
#define RECURSE create_branch(create_branch(create_leaf(S), I), I);

