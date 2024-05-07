#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/trie.h"
#include "../headers/set.h"


Set *
create_set(void) {
    return createTrieNode();
}

void
set_insert_value(Set *root, char *value) {
    insert_value(root, value, "1");
}

int
set_search_value(Set *root, char *value) {
    return search_key(root, value);
}

void
set_erase_value(Set *root, char *value) {
    change_value(root, value, NULL);
}

void
free_set(Set *root) {
    free_trie(root);
}