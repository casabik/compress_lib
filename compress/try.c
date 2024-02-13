#include <stdio.h>
#include <stdlib.h>
#include "../lib/headers/list.h"


int
main(void) {
    L2 list;
    list.head = NULL;
    list.size = 0;
    list.tail = NULL;
    l2_push_back(&list, 12);
    l2_push_back(&list, 11);
    l2_push_front(&list, 2);
    l2_push_front(&list, 3);
    l2_update(&list, 13, 1);
    l2_erase(&list, 3);
    int el = l2_get(&list, 1);
    l2_printf(&list);
    printf("%d\n", el);
    l2_free(&list);
    return 0;
}
