#include <stdio.h>
#include <stdlib.h>
#include "../headers/avl.h"
#include "../headers/tree.h"


int 
avl_find(AVLTree *tree, int elem) {
    AVLNode *current = tree->root;
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

int 
h(AVLNode *node) {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}


int
a_max(int a, int b) {
    return a > b ? a : b;
}

int get_balance(AVLNode *N) {
    if (N == NULL) {
        return 0;
    }
    return h(N->left) - h(N->right);
}


AVLNode *
rotate_left(AVLNode *root) {
    AVLNode *res = root->right;
    AVLNode *right_left_son = root->right->left;
    res->left = root;
    res->left->right = right_left_son;
    res->left->height = a_max(h(res->left->left), h(res->left->right)) + 1;
    res->height = a_max(h(res->left), h(res->right)) + 1;
    return res;
}


AVLNode *
rotate_right(AVLNode *root) {
    AVLNode *res = root->left;
    AVLNode *left_right_son = root->left->right;
    res->right = root;
    res->right->left = left_right_son;
    res->right->height = a_max(h(res->right->right), h(res->right->left)) + 1;
    res->height = a_max(h(res->right), h(res->left)) + 1;
    return res;
}


void
avl_insert(AVLTree *tree, int elem) {
    AVLNode *new_node = calloc(1, sizeof(*new_node));
    new_node->data = elem;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    if (tree->root == NULL) {
        tree->root = new_node;
        return; 
    }
    AVLNode *cur = tree->root;
    AVLNode *parent = NULL;
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

    new_node->height = a_max(h(new_node->left), h(new_node->right)) + 1;

    AVLNode *n = new_node->parent;
    //cделал так, т.к. реализация, где я делал одну проверку не работала
    while (n != NULL) {
        n->height = a_max(h(n->left), h(n->right)) + 1;

        int balance = get_balance(n);

        if (balance > 1 && elem < n->left->data) {
            if (n == tree->root) {
                tree->root = rotate_right(n);
            }
            else n = rotate_right(n);
        }
        else if (balance < -1 && elem > n->right->data) {
            if (n == tree->root) { 
                tree->root = rotate_left(n);
            }
            else n = rotate_left(n);
        }
        else if (balance > 1 && elem > n->left->data) {
            n->left = rotate_left(n->left);
            if (n == tree->root) {
                tree->root = rotate_right(n);
            }
            else n = rotate_right(n);
        }
        else if (balance < -1 && elem < n->right->data) {
            n->right = rotate_right(n->right);
            if (n == tree->root) {
                tree->root = rotate_left(n);
            }
            else n = rotate_left(n);
        }
        n = n->parent;
    }
}

