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

List
*l_push_back(List *list, int elem) {
    if(list == NULL) {
        list = calloc(1, sizeof(*list));
        list->next = NULL;
        list->data = elem;
        return list;
    } else {
        List *res = list;
        while (list -> next != NULL) {
            list = list->next;
        }
        list->next = calloc(1, sizeof(*list));
        list->next->next = NULL;
        list->next->data = elem;
        return res;
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

List *l_erase(List *list, int pos) {
    List *first = list;
    int count = 0;
    if (pos == 0) {
        return list->next;
    }
    while(count != pos) {
        list = list->next;
        count++;
        if(list->next->next == NULL) {
            list->next = NULL;
            return first;
        }
    }
    list->next = list->next->next;
    return first;
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


int
l_count(List *list, int elem) {
    List *new_list = list;
    int count = 0;
    while (1) {
        if (new_list == NULL) {
            return count;
        }
        if (new_list->data == elem) {
            count++;
        }
        new_list = new_list->next;
    }
}
/*
void 
l_free(List *list) {
    List *current = list;
    while (current != NULL) {
        free(current);
        current = current->next;
    }
}*/

void
l2_push_back(L2 *list, int elem) {
    if (list == NULL) {
        fprintf(stderr, "l2_push_back: list is NULL");
        fflush(stderr);
        exit(1);
    }
    if (list->size == 0) {
        list->head = calloc(1, sizeof(*list->head));
        list->head->data = elem;
        list->head->prev = NULL; 
        list->head->next = NULL;
        list->tail = list->head;
        list->size++;
    } else {
        list->tail->next = calloc(1, sizeof(*list->head));
        list->tail->next->data = elem;
        list->tail->next->next = NULL;
        list->tail->next->prev = list->tail;
        list->tail = list->tail->next;
        list->size++;
    }
}

void
l2_push_front(L2 *list, int elem) {
    if (list == NULL) {
        fprintf(stderr, "l2_push_front: list is NULL");
        fflush(stderr);
        exit(1);
    }
    if (list->size == 0) {
        list->head = calloc(1, sizeof(*list->head));
        list->head->data = elem;
        list->head->prev = NULL; 
        list->head->next = NULL;
        list->tail = list->head;
        list->size++;
    } else {
        list->head->prev = calloc(1, sizeof(*list->head));
        list->head->prev->data = elem;
        list->head->prev->prev = NULL;
        list->head->prev->next = list->head;
        list->head = list->head->prev;
        list->size++;
    }
}

void
l2_insert(L2 *list, int elem, int pos) {
    if (list == NULL) {
        fprintf(stderr, "l2_insert: list is NULL");
        fflush(stderr);
        exit(1);
    }
    if (list->size == 0) {
        list->head = calloc(1, sizeof(*list->head));
        list->head->data = elem;
        list->tail->prev = NULL; 
        list->head->next = NULL;
        list->tail = list->head;
        list->size++;
    } else {
        list->head->prev = calloc(1, sizeof(*list->head));
        list->head->prev->data = elem;
        list->head->prev->prev = NULL;
        list->head->prev->prev = list->head;
        list->head = list->head->prev;
        list->size++;
    }
}

void
l2_printf(L2 *list) {
    if (list == NULL) {
        fprintf(stderr, "l2_printf: list is NULL");
        fflush(stderr);
        exit(1);
    }
    while(list->head != NULL) {
        printf("%d\n", list->head->data);
        list->head = list->head->next;
    }
    printf("\n");
}

