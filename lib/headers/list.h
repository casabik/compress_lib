#ifndef LIST_H
#define LIST_H

typedef struct List {
    int data;
    struct List *next;
} List;

extern List *l_printf(List *list);
extern List *l_init(List *list, int elem);
extern List *l_push_back(List *list, int elem);
extern List *l_insert(List *list, int elem, int pos);
extern List *l_erase(List *list, int pos);
extern List *l_update(List *list, int elem, int pos);
extern int l_get(List *list, int pos);
extern int l_find(List *list, int elem);

#endif
