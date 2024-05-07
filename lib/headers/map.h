#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include "../headers/trie.h"

typedef TrieNode Map;

Map *create_map(void);
void map_insert_value(Map *root, char *key, char *value);
char *map_find_value(Map *root, char *key);
void map_erase_key(Map *root, char *key);
int map_search_key(Map *root, char *key);
void map_change_value(Map *root, char *key, char *value);
void free_map(Map *root);

#endif