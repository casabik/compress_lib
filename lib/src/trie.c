#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/trie.h"

TrieNode
*createTrieNode(void) {
    TrieNode *newNode = calloc(1, sizeof(TrieNode));
    if (!newNode) {
        fprintf(stderr, "createTrieNode: memory error\n");
        fflush(stderr);
        exit(1);
    }
    
    if (newNode) {
        for (int i = 0; i < MAX_CHILDREN; i++)
            newNode->children[i] = NULL;
        newNode->value = NULL;
    }
    return newNode;
}


void 
insert_value(TrieNode *root, char *key, char *value) {
    TrieNode *node = root;
    
    while(*key) {
        int index = (unsigned char)(*key);
        if (node->children[index] == NULL) {
            node->children[index] = createTrieNode();
        }
        node = node->children[index];
        key++;
    }
    
    node->value = value;
}


char *
find_value(TrieNode *root, char *key) {
    TrieNode *node = root;
    
    while(*key) {
        int index = (unsigned char)(*key);
        if (!node->children[index]) {
            return NULL;
        }
        node = node->children[index];
        key++;
    }
    return node->value; 
}


int
search_key(TrieNode *root, char *key) {
    TrieNode *node = root;
    
    while(*key) {
        int index = (unsigned char)(*key);
        if (!node->children[index]) {
            return 0;
        }
        node = node->children[index];
        key++;
    }
    if (!node->value) {
        return 0;
    }
    return 1;
}

void erase_key(TrieNode *root, char *key) {
    TrieNode *node = root;

    while(*key) {
        int index = (unsigned char)(*key);
        if (!node->children[index]) {
            fprintf(stderr, "erase_key: no such key\n");
            fflush(stderr);
            exit(1);
        }
        node = node->children[index];
        key++;
    }
    
    if (node->value) {
        node->value = NULL; 
    }
}

void
change_value(TrieNode *root, char *key, char *value) {
    TrieNode *node = root;
    
    while(*key) {
        int index = (unsigned char)(*key);
        if (!node->children[index]) {
            fprintf(stderr, "change_value: no such key\n");
            fflush(stderr);
            exit(1);
        }
        node = node->children[index];
        key++;
    }
    node->value = value; 
}

void 
free_trie(TrieNode *root) {
    int i;
    for (i = 0; i < MAX_CHILDREN; i++) {
        if (root->children[i]) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

