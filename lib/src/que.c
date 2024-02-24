#include "../headers/que.h"
#include <stdio.h>
#include <stdlib.h>

void 
d_push_back(Deque *deque, int elem) {
    if (deque == NULL) {
        fprintf(stderr, "d_push_back: deque is NULL");
        fflush(stderr);
        exit(1);
    }
    if (deque->size == 0) {
        deque->head = calloc(1, sizeof(*deque->head));
        deque->head->data = elem;
        deque->head->prev = NULL; 
        deque->head->next = NULL;
        deque->tail = deque->head;
        deque->size++;
    } else {
        deque->tail->next = calloc(1, sizeof(*deque->head));
        deque->tail->next->data = elem;
        deque->tail->next->next = NULL;
        deque->tail->next->prev = deque->tail;
        deque->tail = deque->tail->next;
        deque->size++;
    }
 }

void
d_push_front(Deque *deque, int elem) {
    if (deque == NULL) {
        fprintf(stderr, "d_push_front: deque is NULL");
        fflush(stderr);
        exit(1);
    }
    if (deque->size == 0) {
        deque->head = calloc(1, sizeof(*deque->head));
        deque->head->data = elem;
        deque->head->prev = NULL; 
        deque->head->next = NULL;
        deque->tail = deque->head;
        deque->size++;
    } else {
        deque->head->prev = calloc(1, sizeof(*deque->head));
        deque->head->prev->data = elem;
        deque->head->prev->prev = NULL;
        deque->head->prev->next = deque->head;
        deque->head = deque->head->prev;
        deque->size++;
    }
}

int 
d_pop_front(Deque *deque) {
    if (deque == NULL || deque->size == 0) {
        fprintf(stderr, "p_pop_front: deque is NULL");
        fflush(stderr);
        exit(1);
    }
    if (deque->size == 1) {
        int data = deque->head->data;
        free(deque->head);
        deque->head = NULL;
        deque->size--;
        return data;
    } else {
        int data = deque->head->data;
        deque->head = deque->head->next;
        free(deque->head->prev);
        deque->head->prev = NULL;
        deque->size--;
        return data;
    }
    
}

int
d_pop_back(Deque *deque) {
    if (deque == NULL || deque->size == 0) {
        fprintf(stderr, "p_pop_back: deque is NULL");
        fflush(stderr);
        exit(1);
    }
    if (deque->size == 1) {
        int data = deque->tail->data;
        free(deque->tail);
        deque->tail = NULL;
        deque->size--;
        return data;
    } else {
        int data = deque->tail->data;
        deque->tail = deque->tail->prev;
        free(deque->tail->next);
        deque->tail->next = NULL;
        deque->size--;
        return data;
    }
}

int
d_size(Deque *deque) {
    if (deque == NULL || deque->size == 0) {
        fprintf(stderr, "d_size: deque is NULL");
        fflush(stderr);
        exit(1);
    }
    return deque->size;
}

int
d_empty(Deque *deque) {
    if (deque == NULL || deque->size == 0) {
        return 0;
    } else {
        return 1;
    }
}

int 
d_front(Deque *deque) {
    if (deque == NULL) {
        fprintf(stderr, "d_front: deque is NULL");
        fflush(stderr);
        exit(1);
    }
    return deque->head->data;
}

int 
d_back(Deque *deque) {
    if (deque == NULL) {
        fprintf(stderr, "d_back: deque is NULL");
        fflush(stderr);
        exit(1);
    }
    return deque->tail->data;
}

void
d_free(Deque *deque) {
    if (deque == NULL) {
        fprintf(stderr, "d_free: deque is NULL");
        fflush(stderr);
        exit(1);
    }
    for (int i = 0; i < deque->size; i++) {
        d_pop_back(deque);
    }
    deque->head = NULL;
    deque->tail = NULL;
    deque->size = 0;
}

void 
d_printf(Deque *deque) {
    if (deque == NULL) {
        fprintf(stderr, "d_printf: deque is NULL");
        fflush(stderr);
        exit(1);
    }
    L2Node *deq = deque->head;
    while(deq != NULL) {
        printf("%d\n", deq->data);
        deq = deq->next;
    }
}

void 
s_push_back(Stack *stack, int elem) {
    d_push_front(stack, elem);
}

int 
s_pop(Stack *stack) {
    return d_pop_front(stack);
}

int
s_top(Stack *stack) {
    return d_front(stack);
}
int
s_size(Stack *stack) {
    return d_size(stack);
}

int 
s_empty(Stack *stack) {
    if (stack == NULL || stack->size == 0) {
        return 0;
    } else {
        return 1;
    }
}


void
s_free(Stack *stack) {
    d_empty(stack);
}

void 
s_printf(Stack *stack) {
    d_printf(stack);
}

void 
enqueue(Queue *queue, int elem) {
    d_push_back(queue, elem);
}

int
dequeue(Queue *queue) {
    return d_pop_front(queue);
}

int
q_empty(Queue *queue) {
    if (queue == NULL || queue->size == 0) {
        return 0;
    } else {
        return 1;
    }
}

int
q_top(Queue *queue) {
    return d_front(queue);
}

void
q_free(Queue *queue) {
    d_empty(queue);
}
int 
q_size(Queue *queue) {
    return d_size(queue);
}

void 
q_printf(Queue *queue) {
    d_printf(queue);
}