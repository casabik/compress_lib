#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include <stdio.h>
#include "../headers/list.h"

typedef struct HashTable { 
    unsigned short (*hash)(char *str); 
    Listr *arr[1 << 16]; 
} HashTable; 

extern HashTable *h_init(unsigned short (*hash)(char *str));
extern void h_insert(HashTable *hash_table, char *str); 
extern void h_erase(HashTable *hash_table, char *str); 
extern char *h_find(HashTable *hash_table, char *str); 
extern void h_free(HashTable *hash_table);

#endif