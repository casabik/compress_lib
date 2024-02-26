#include "../headers/tree.h"
#include "../headers/vector.h"
#include <stdio.h>
#include <stdlib.h>


void
swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

TreeNode 
*init_node(int value) {
    TreeNode *new_one = calloc(1, sizeof(TreeNode));
    new_one->data = value;
    new_one->left = new_one->right = new_one->parent = NULL;
    return new_one;
}


void
h_insert(Heap *heap, int value) {
    TreeNode *new_one = init_node(value);

    if (heap->root == NULL) {
        heap->root = new_one;
        return;
    }

    TreeNode *node = heap->root;
    while (node->left != NULL && node->right != NULL) {
        if (node->left != NULL && node->right != NULL) {
            if (node->left->data < node->right->data) {
                node = node->left;
            } else {
                node = node->right;
            }
        } else {
            if (node->left != NULL) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }

    if (node->left == NULL) {
        node->left = new_one;
    } else {
        node->right = new_one;
    }

    new_one->parent = node;

    while (new_one->parent != NULL && new_one->parent->data < new_one->data) {
        swap(&new_one->data, &new_one->parent->data);
        new_one = new_one->parent;
    }
}


int
h_erase_root(Heap *heap) {
    if (heap->root == NULL) {
        fflush(stderr);
        fprintf(stderr, "Heap is empty\n");
        exit(1);
    }

    int rootValue = heap->root->data;

    if (heap->root->left == NULL && heap->root->right == NULL) {
        free(heap->root);
        heap->root = NULL;
        return rootValue;
    }

    TreeNode *last_one = heap->root;
    while (last_one->left != NULL || last_one->right != NULL) {
        if (last_one->right != NULL)
            last_one = last_one->right;
        else
            last_one = last_one->left;
    }

    if (last_one->parent->left == last_one)
        last_one->parent->left = NULL;
    else
        last_one->parent->right = NULL;

    heap->root->data = last_one->data;
    free(last_one);

    TreeNode *current = heap->root;
    while (current->left != NULL || current->right != NULL) {
        TreeNode *max_node = current;
        TreeNode *left_child = current->left;
        TreeNode *left_child = current->right;
        if (left_child != NULL && left_child->data > max_node->data) {
            max_node = left_child;
        }
        if (left_child != NULL && left_child->data > max_node->data) {
            max_node = left_child;
        }

        if (max_node == current) {
            break;
        }
        int temp = current->data;
        current->data = max_node->data;
        max_node->data = temp;

        current = max_node;
    }

    return rootValue;
}


void
bst_insert(BSTree *tree, int elem) {
    TreeNode *new_node = calloc(1, sizeof(*new_node));
    new_node->data = elem;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    if (tree->root == NULL) {
        tree->root = new_node;
        return; 
    }
    TreeNode *cur = tree->root;
    TreeNode *parent = NULL;
    while (cur != NULL) {
        parent = cur;
        if (elem < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    new_node->parent = parent;
    if (elem < parent->data) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}


int 
bst_find(BSTree *tree, int elem) {
    TreeNode *current = tree->root;
    while (current != NULL) {
        if (current->data == elem) {
            return 1;
        } else if (current->data < elem) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return 0;
}


void 
transplant(BSTree *tree, TreeNode *old, TreeNode *new) {
    if (old->parent == NULL) {
        tree->root = new;
    } else if (old == old->parent->left) {
        old->parent->left = new;
    } else {
        old->parent->right = new;
    }
    if (new != NULL) {
        new->parent = old->parent;
    }
}


TreeNode* 
min_node(TreeNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}


void 
bst_erase(BSTree *tree, int elem) {
    TreeNode *current = tree->root;
    int check = 0;
    while (current != NULL) {
        if (current->data == elem) {
            check = 1;
            break;
        } else if (current->data < elem) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    if (check == 0) {
        fprintf(stderr, "bst_erase: tree doesn't contain elem\n");
        fflush(stderr);
        exit(1);
    }
    if (current->left == NULL) {
        transplant(tree, current, current->right);
    } else if (current->right == NULL) {
        transplant(tree, current, current->left);
    } else {
        TreeNode *new_node = min_node(current->right);
        if (new_node->parent != current) {
            transplant(tree, new_node, new_node->right);
            new_node->right = current->right;
            new_node->right->parent = new_node;
        }
        transplant(tree, current, new_node);
        new_node->left = current->left;
        new_node->left->parent = new_node;
    }
    free(current);
}


void 
recurse_vector(TreeNode *node, Vector *vector) {
    if (node == NULL) {
        return;
    }
    recurse_vector(node->left, vector);
    v_push_back(vector, node->data);
    recurse_vector(node->right, vector);
}


Vector bst_to_vector(BSTree *tree) {
    Vector vector;
    v_init(&vector);
    recurse_vector(tree->root, &vector);
    return vector;
}