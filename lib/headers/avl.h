#ifndef AVL_H
#define AVL_H

#include <stdlib.h>
#include "../headers/vector.h"

typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
    struct AVLNode *parent;
} AVLNode;
 
typedef struct AVLTree {
    AVLNode *root;
} AVLTree;


extern void avl_insert(AVLTree *tree, int elem);
extern void avl_erase(AVLTree *tree, int elem);
extern int avl_find(AVLTree *tree, int elem);
extern void avl_print(AVLTree *tree);

#endif

