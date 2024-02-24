#include <stdio.h>
#include <stdlib.h>
#include "../lib/headers/tree.h"

int
main(void) {
    BSTree *tree = calloc(1, sizeof(BSTree));
    tree->root = NULL;
    bst_insert(tree, 1);
    bst_insert(tree, 2);
    bst_insert(tree, 4);
    bst_insert(tree, -23);
    bst_insert(tree, 5);
    bst_erase(tree, 1);
    bst_erase(tree, -23);
    bst_erase(tree, 5);
    printf("find: %d\n", bst_find(tree, 12));
    Vector arr = bst_to_vector(tree);
    v_printf(&arr);
    printf("\n");
    return 0;
}
