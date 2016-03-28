#include "tree.h"



// Identity combinator
// IDENTITY x y = x y
#define IDENTITY create_branch(create_branch(create_leaf(S), create_leaf(K)), create_leaf(K))

// Recursion combinator
// RECURSE a = I a (I a) = a a
#define RECURSE create_branch(create_branch(create_leaf(S), IDENTITY), IDENTITY)

// Self-application combinator
// SELFAPP b = 0 (b b)
#define BETA create_branch(create_branch(create_leaf(S), create_branch(create_leaf(K), create_leaf(42))), RECURSE)

// Reversal combinator
// REVERSE a b = b a
#define REVERSE create_branch(create_branch(create_leaf(S), create_branch(create_leaf(K), create_branch(create_leaf(S), IDENTITY))), create_leaf(K))