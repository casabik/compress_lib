#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/map.h"
#include "../headers/trie.h"

Map *
create_map(void) {
    return createTrieNode();
}

void
map_insert_value(Map *root, char *key, char *value) {
    insert_value(root, key, value);
}

void 
map_erase_key(Map *root, char *key) {
    erase_key(root, key);
}

char *
map_find_value(Map *root, char *key) {
    return find_value(root, key);
}

int
map_search_key(Map *root, char *key) {
    return search_key(root, key);
}

void 
map_change_value(Map *root, char *key, char *value) {
    change_value(root, key, value);
}

void
free_map(Map *root) {
    free_trie(root);
}
