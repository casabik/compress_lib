#include "../headers/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

List *
l_erase(List *list, int pos) {
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

Listr *
lstr_printf(Listr *list) {
    Listr *new_list = list;
    while(new_list != NULL) {
        printf("%s\n", new_list->data);
        new_list = new_list->next;
    }
    return list;
}


Listr *
lstr_push_back(Listr *list, char *elem) {
    if(list == NULL) {
        list = calloc(1, sizeof(*list));
        list->next = NULL;
        list->data = elem;
        return list;
    } else {
        Listr *res = list;
        while (list -> next != NULL) {
            list = list->next;
        }
        list->next = calloc(1, sizeof(*list));
        list->next->next = NULL;
        list->next->data = elem;
        return res;
    }
}


Listr *
lstr_erase(Listr *list, char* value) {
    Listr *current = list, *prev = NULL;
    while (current != NULL && strcmp(current->data, value) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) 
        return list;

    if (prev == NULL) {
        Listr *temp = list;
        list = list->next;
        free(temp->data);
        free(temp);
    } else {
        prev->next = current->next;
        free(current->data);
        free(current);
    }

    return list;
}


char *
lstr_find(Listr *list, char *elem) {
    Listr *current = list;
    while (current != NULL) {
        if (strcmp(current->data, elem) == 0) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

void 
lstr_free(Listr *list) {
    Listr *temp;
    while (list != NULL) {
        temp = list;
        list = list->next; 
        free(temp->data);
        free(temp);
    }
}

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
    if (list == NULL || pos < 0 || pos >= list->size) {
        fprintf(stderr, "l2_insert: invalid parameters\n");
        fflush(stderr);
        exit(1);
    }
    if (list->size - pos >= pos) {
        L2Node *new_l = calloc(1, sizeof(L2Node)); 
        L2Node *l = list->head;
        if (pos == 0) {
            new_l->data = elem;
            new_l->next = l;
            new_l->prev = NULL;
            l->prev = new_l;
            list->head = new_l;
        } else {
            for(int i = 0; i < pos; i++) {
                if (l == NULL) {
                    exit(1);
                }
                l = l->next;
            }
            new_l->data = elem;
            new_l->next = l;
            new_l->prev = l->prev;
            l->prev = new_l;
            l->prev->prev->next = new_l;
        }
    } else {
        L2Node *new_l = calloc(1, sizeof(L2Node)); 
        L2Node *l = list->tail;
        for(int i = list->size - 1; i > pos; i--) {
            if (l == NULL) {
                exit(1);
            }
            l = l->prev;
        }
        new_l->data = elem;
        new_l->next = l;
        new_l->prev = l->prev;
        l->prev = new_l;
        l->prev->prev->next = new_l;
    }
    list->size++;
}



void 
l2_update(L2 *list, int elem, int pos) {
    if (list == NULL || pos < 0 || pos >= list->size) {
        fprintf(stderr, "l2_update: invalid parameters\n");
        fflush(stderr);
        exit(1);
    }
    if (list->size - pos >= pos) {
        L2Node *l = list->head;
        for(int i = 0; i < pos; i++) {
            if (l == NULL) {
                exit(1);
            }
            l = l->next;
        }
        l->data = elem;
    } else {
        L2Node *l = list->tail;
        for(int i = list->size - 1; i > pos; i--) {
            if (l == NULL) {
                exit(1);
            }
            l = l->prev;
        }
        l->data = elem;
    }
}

int
l2_get(L2 *list, int pos) {
	if (pos < 0 || pos >= list->size || list == NULL) {
        fprintf(stderr, "l2_get: invalid parameters\n");
        fflush(stderr);
        exit(1);
    }
    if (list->size - pos >= pos) {
        L2Node *new_list = list->head;
        for(int i = 0; i < pos; i++) {
            if (new_list == NULL) {
                exit(1);
            }
            new_list = new_list->next;
        }
        return new_list->data;
    } else {
        L2Node *new_list = list->tail;
        for(int i = list->size - 1; i > pos; i--) {
            if (new_list == NULL) {
                exit(1);
            }
            new_list = new_list->prev;
        }
        return new_list->data;
    }
}

L2Node 
*l2_find(L2 *list, int elem) {
	if (list == NULL) {
        fprintf(stderr, "l2_get: invalid parameters\n");
        fflush(stderr);
        exit(1);
    }
    L2Node *new_list = list->head;
    while (1) {
        if (new_list == NULL) {
            fprintf(stderr, "l2_get: invalid parameters\n");
            fflush(stderr);
            exit(1);
        }
        if (new_list->data == elem) {
            return new_list;
        }
        new_list = new_list->next;
    }
}

void 
l2_erase(L2 *list, int pos) {
    if (pos < 0 || pos >= list->size || list == NULL) {
        fprintf(stderr, "l2_get: invalid parameters\n");
        fflush(stderr);
        exit(1);
    }
    if (list->size - pos >= pos) {
        L2Node *l = list->head;
        if (pos == 0) {
            list->head = l->next;
            list->head->prev = NULL;
        } else {
            for(int i = 0; i < pos; i++) {
                if (l == NULL) {
                    exit(1);
                }
                l = l->next;
            }
            l->prev->next = l->next;
            l->next->prev = l->prev;
        }
    } else {
        L2Node *l = list->tail;
        if (pos == list->size - 1) {
            list->tail = l->prev;
            list->tail->next = NULL;
        } else {
            for(int i = list->size - 1; i > pos; i--) {
                if (l == NULL) {
                    exit(1);
                }
                l = l->prev;
            }
            l->prev->next = l->next;
            l->next->prev = l->prev;
        }
    }
    list->size--;
}

void
l2_free(L2 *list) {
    L2Node *l = list->head;
    while (l != NULL) {
        L2Node *tmp = l;
        l = l->next;
        free(tmp);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void
l2_printf(L2 *list) {
    if (list == NULL) {
        fprintf(stderr, "l2_printf: list is NULL");
        fflush(stderr);
        exit(1);
    }
    L2Node *l = list->head;
    while(l != NULL) {
        printf("%d\n", l->data);
        l = l->next;
    }
}