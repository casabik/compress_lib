#include <string.h>
#include <stdlib.h>
#include <stdio.h> 
#include "../lib/headers/hash.h"


unsigned short MurmurHash2(char *key) {
    const unsigned int m = 0x5bd1e995;
    const unsigned int seed = 0;
    const int r = 24;
    unsigned int len = strlen(key);
    unsigned int h = seed ^ len;

    const unsigned char *data = (const unsigned char *)key;
    unsigned int k = 0;

    while (len >= 4) {
        k  = data[0];
        k |= data[1] << 8;
        k |= data[2] << 16;
        k |= data[3] << 24;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    switch (len) {
        case 3:
            h ^= data[2] << 16;
        case 2:
            h ^= data[1] << 8;
        case 1:
            h ^= data[0];
            h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return (unsigned short)(h % 65536) + 1;
}


int main() {
    char *key = "key";
    unsigned int hashValue = MurmurHash2(key);
    printf("hash: %u\n", hashValue);
    HashTable *hash_table = h_init(MurmurHash2);
    h_insert(hash_table, "григорий это не найдет");
    h_insert(hash_table, "12345");
    h_insert(hash_table, "курсы по скоропечатанью");
    printf("hash: %s\n", h_find(hash_table, "григорий это не найдет"));
    printf("hash: %s\n", h_find(hash_table, "12345"));
    h_erase(hash_table, "григорий это не найдет");
    printf("hash: %s\n", h_find(hash_table, "григорий это не найдет"));
    h_free(hash_table);
    return 0;
}