#ifndef TREE_H
#define TREE_H

#include <stdio.h>

#define MAX_CHILDREN 256  
//эта штука нужна для реализации алгортим LZV(что-то типо словаря для поиска айди последовательности(строки) за ассимптотику O(1))

typedef struct TrieNode {
    struct TrieNode *children[MAX_CHILDREN];
    char *value;
} TrieNode;

TrieNode *createTrieNode(void);
void insert_value(TrieNode *root, char *key, char *value);
char *find_value(TrieNode *root, char *key);
int search_key(TrieNode *root, char *key);
void erase_key(TrieNode *root, char *key);
void change_value(TrieNode *root, char *key, char *value);
void free_trie(TrieNode *root);

#endif