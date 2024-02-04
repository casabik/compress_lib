#include "../headers/vector.h"
#include <stdio.h>
#include <stdlib.h>


void
v_init (Vector *vector) {
	int* arr;
	int size = 0;
	vector->size = size;
	vector->capacity = 10000;
	arr = calloc(vector->capacity, sizeof(*arr));
	vector->data = arr;
}

void
v_push_back(Vector *vector, int elem) {
	if (vector->size + 1 <= vector->capacity) {
		vector->size++;
		vector->data[vector->size - 1] = elem;
	} else {
		int *new_data = realloc(vector->data, 2 * vector->capacity);
		if (new_data == NULL) {
			exit(1);
		}
		vector->data = new_data;
		vector->size++;
		vector->capacity *= 2;
		vector->data[vector->size - 1] = elem;
	}
}


void
v_insert(Vector *vector, int elem, int pos) {
	if (vector->size + 1 <= vector->capacity) {
                vector->size++;
                vector->data[pos] = elem;
        } else {
                int *new_data = realloc(vector->data, 2 * vector->capacity);
                if (new_data == NULL) {
                        exit(1);
                }
                vector->data = new_data;
                vector->size++;
                vector->capacity *= 2;
                vector->data[pos] = elem;
        }
}

void
v_erase(Vector *vector, int pos) {
	int start = pos + 1;
	for (int i = start; i < vector->size; i++) {
		vector->data[i - 1] = vector->data[i];
	}
}

void
v_update(Vector *vector, int elem, int pos) {
	vector->data[pos] = elem;
}

int
v_get(Vector *vector, int pos) {
	return vector->data[pos];
}

void
v_free(Vector *vector) {
    free(vector->data);
    vector->size = 0;
    vector->capacity = 0;
}
