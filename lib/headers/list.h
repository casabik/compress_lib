#include <stdlib.h>
#ifndef LIST_H
#define LIST_H

typedef struct List {
    int data;
    struct List *next;
} List;

typedef struct L2Node {
    int data;
    struct L2Node *prev;
    struct L2Node *next;
} L2Node;
 
typedef struct L2 {
    struct L2Node *head;
    struct L2Node *tail;
    size_t size;
} L2;

extern List *l_printf(List *list);
extern List *l_push_back(List *list, int elem);
extern List *l_insert(List *list, int elem, int pos);
extern List *l_erase(List *list, int pos);
extern List *l_update(List *list, int elem, int pos);
extern int l_get(List *list, int pos);
extern int l_find(List *list, int elem);
extern int l_count(List *list, int elem);

extern void l2_push_back(L2 *list, int elem);
extern void l2_push_front(L2 *list, int elem);
extern void l2_insert(L2 *list, int elem, int pos);
extern void l2_erase(L2 *list, int pos);
extern void l2_update(L2 *list, int elem, int pos);
extern int l2_get(L2 *list, int pos);
extern L2Node *l2_find(L2 *list, int elem);
extern void l2_printf(L2*list);


#endif
