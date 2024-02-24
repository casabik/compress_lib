#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include "../headers/vector.h"

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;
 
typedef struct Tree {
    TreeNode *root;
} Tree;

typedef Tree Heap;
typedef Tree BSTree;

extern void h_insert(Heap *heap, int elem);
extern void h_erase_root(Heap *heap);
extern void h_make(TreeNode *node);
extern void swap(void *a, void *b);
extern void bst_insert(BSTree *tree, int elem);
extern void bst_erase(BSTree *tree, int elem);
extern int bst_find(BSTree *tree, int elem);
extern void transplant(BSTree *tree, TreeNode *old, TreeNode *new);
extern TreeNode* min_node(TreeNode *node);
extern Vector bst_to_vector(BSTree *tree);

#endif
