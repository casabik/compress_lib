#include "../headers/list.h"
#include <stdio.h>
#include <stdlib.h>


List *
l_push_back(List *list, int elem) {
	return NULL;
}

List *
l_insert(List *list, int elem, int pos) {
	return NULL;
}

List *
l_erase(List *list, int pos) {
	return NULL;
}

List *
l_update(List *list, int elem, int pos) {
	return NULL;
}


int
l_get(List *list, int pos) {
	if (pos < 0 || list != NULL) {
        exit(1);
    }
    if (pos == 0) {
        return list->data;
    } else {
        return l_get(list->next, pos - 1);
    }
}