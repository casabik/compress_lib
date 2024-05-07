#include <string.h>
#include <stdlib.h>
#include <stdio.h> 
#include "../lib/headers/set.h"
#include "../lib/headers/map.h"

int main() {
    Set *set = create_set();
    printf("Set tests\n");
    set_insert_value(set, "a");
    set_insert_value(set, "b");
    set_insert_value(set, "c");
    set_insert_value(set, "bogdan");
    printf(set_search_value(set, "a") ? "true\n" : "false\n");

    set_erase_value(set, "a");
    printf(set_search_value(set, "a") ? "true\n" : "false\n");

    printf(set_search_value(set, "bogdan") ? "true\n" : "false\n");
    free_set(set);

    Map *map = create_map();
    printf("Map tests\n");
    map_insert_value(map, "opa", "tut");
    map_insert_value(map, "awdadawd", "ugu");
    map_insert_value(map, "prokaznik", "bogdan");
    printf("%d\n", map_search_key(map, "awdadawd"));
    printf("%s\n", map_find_value(map, "opa"));
    printf("%s\n", map_find_value(map, "awdadawd"));
    printf("%s\n", map_find_value(map, "prokaznik"));

    map_erase_key(map, "awdadawd");
    printf("%d\n", map_search_key(map, "awdadawd"));

    free_map(map);
    return 0;
}