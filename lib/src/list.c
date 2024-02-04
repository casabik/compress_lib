#include "../headers/list.h"
#include <stdio.h>
#include <stdlib.h>


List *
l_printf(List *list) {
    List *new_list = list;
    while(new_list != NULL) {
        printf("%d\n", new_list->data);
        new_list = new_list->next;
    }
    return list;
}


List *
l_init(List *list, int elem) {
    list = calloc(1, sizeof(List));
    list->data = elem;
    list->next = NULL;
    return list;
}

List *
l_push_back(List *list, int elem) {
    List *new_list = list;
    while(1) {
        if (new_list->next == NULL) {
            List *new_elem = calloc(1, sizeof(List));
            new_elem->data = elem;
            new_list->next = new_elem;
            new_elem->next = NULL;
            return list;
        }
        new_list = new_list->next;
    }
}

List *
l_insert(List *list, int elem, int pos) {
    List *new_list = list;
    if (pos == 0) {
        List *l = calloc(1, sizeof(List));
        l->data = elem;
        l->next = list;
        return l;
    }
    if (pos < 0 || list == NULL) {
        exit(1);
    }
    for(int i = 0; i < pos - 1; i++) {
        if (list == NULL) {
            exit(1);
        }
        list = list->next;
    }
    List *l = calloc(1, sizeof(List));
    l->data = elem;
    l->next = list->next;
    list->next = l;
    return new_list;
}

List *
l_erase(List *list, int pos) {
    if (pos < 0 || list == NULL) {
        exit(1);
    }
    if (pos == 0) {
        List *new_list = list->next;
        free(list); 
        return new_list;
    }
    List *new_list = list;
    for(int i = 0; i < pos - 1; i++) {
        if (list == NULL) {
            exit(1);
        }
        list = list->next;
    }
    List *prev = list;
    list = list->next;
    if (list != NULL) {
        prev->next = list->next; 
        free(list); 
    }
    return new_list;
}

List *
l_update(List *list, int elem, int pos) {
    List *new_list = list;
	if (pos < 0 || list == NULL) {
        exit(1);
    }
    for(int i = 0; i < pos; i++) {
        if (list == NULL) {
            exit(1);
        }
        list = list->next;
    }
    list->data = elem;
    return new_list;
}


int
l_get(List *list, int pos) {
    List *new_list = list;
	if (pos < 0 || new_list == NULL) {
        exit(1);
    }
    if (pos == 0) {
        return list->data;
    }
    for(int i = 0; i < pos; i++) {
        if (new_list == NULL) {
            exit(1);
        }
        new_list = new_list->next;
    }
    return new_list->data;
}

int
l_find(List *list, int elem) {
    List *new_list = list;
    int count = 0;
    while (1) {
        if (new_list == NULL) {
            exit(1);
        }
        if (new_list->data == elem) {
            return count;
        }
        new_list = new_list->next;
        count++;
    }
}
