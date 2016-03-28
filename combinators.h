#include "tree.h"

// Tree * K23 = create_branch(create_branch(create_leaf(K), create_leaf(0)), create_leaf(1));
// Tree * S234 = create_branch(create_branch(create_branch(create_leaf(S), create_leaf(0)), create_leaf(1)), create_leaf(2));

// Identity combinator
// IDENTITY x y = x y
#define IDENTITY create_branch(create_branch(create_leaf(S), create_leaf(K)), create_leaf(K))
// Tree * tree = create_branch(create_branch(IDENTITY, create_leaf(1)), create_leaf(1))

// Recursion combinator
// RECURSE a = I a (I a) = a a
#define RECURSE create_branch(create_branch(create_leaf(S), IDENTITY), IDENTITY)
// Tree * tree = create_branch(RECURSE, create_leaf(42));

// Self-application combinator
// SELFAPP b = 0 (b b)
#define BETA create_branch(create_branch(create_leaf(S), create_branch(create_leaf(K), create_leaf(42))), RECURSE)
// Tree * tree = create_branch(BETA, BETA)

// Reversal combinator
// REVERSE a b = b a
#define REVERSE create_branch(create_branch(create_leaf(S), create_branch(create_leaf(K), create_branch(create_leaf(S), IDENTITY))), create_leaf(K))
// Tree * tree = create_branch(create_branch(REVERSE, create_leaf(0)), create_leaf(1));