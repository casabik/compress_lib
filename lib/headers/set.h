#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include "../headers/trie.h"

typedef TrieNode Set;

Set *create_set(void);
void set_insert_value(Set *root, char *value);
int set_search_value(Set *root, char *value);
void set_erase_value(Set *root, char *value);
void free_set(Set *root);

#endif