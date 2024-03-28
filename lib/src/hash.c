#include "../headers/hash.h"
#include "../headers/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashTable *
h_init(unsigned short (*hash)(char *str)) {
    HashTable *hash_table = calloc(1, sizeof(HashTable));
    hash_table->hash = hash;
    return hash_table;
}

void 
h_insert(HashTable *hash_table, char *str) {
    unsigned int index = hash_table->hash(str);
    hash_table->arr[index] = lstr_push_back(hash_table->arr[index], strdup(str));
}

void 
h_erase(HashTable *hash_table, char *str) {
    unsigned int index = hash_table->hash(str);
    hash_table->arr[index] = lstr_erase(hash_table->arr[index], strdup(str));
}


char *
h_find(HashTable *hash_table, char *str){
    unsigned int index = hash_table->hash(str);
    return lstr_find(hash_table->arr[index], strdup(str));
}

void
h_free(HashTable *hash_table){
    free(hash_table);
}
