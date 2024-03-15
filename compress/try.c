#include <stdio.h>
#include <stdlib.h>
#include "../lib/headers/avl.h"

int
main(void) {
    AVLTree *tree = calloc(1, sizeof(AVLTree));
    tree->root = NULL;
    avl_insert(tree, 1);
    avl_insert(tree, 2);
    avl_insert(tree, 4);
    avl_insert(tree, 5);
    avl_insert(tree, 3);
    avl_insert(tree, 123);
    avl_insert(tree, 0);
    avl_print(tree);
    return 0;
}
