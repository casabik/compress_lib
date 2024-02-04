#include <stdio.h>
#include <stdlib.h>
#include "../lib/headers/list.h"


int
main(void) {
    List list;
    list = *l_init(&list, 1);
    list = *l_push_back(&list, 52);
    list = *l_push_back(&list, 11);
    list =  *l_insert(&list, 53, 1);
    list = *l_update(&list, 54, 1);
    list =  *l_erase(&list, 0);
    list = *l_printf(&list);
    return 0;
}
