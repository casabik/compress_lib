#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "list.h"

typedef L2 Stack;
typedef L2 Queue;
typedef L2 Deque;

extern void s_init(Stack *stack);
extern void s_push_back(Stack *stack, void *elem);
extern int s_pop(Stack *stack);
extern int s_top(Stack *stack);
extern void s_empty(Stack *stack);
extern void s_free(Stack *stack);


extern void q_init(Deque *duque);
extern void enqueue(Queue *queue, int elem);
extern void dequeue(Queue *queue, int elem);
extern void q_empty(Deque *deque);
extern int q_top(Deque *deque);
extern void q_free(Deque *deque);

extern void d_init(Deque *duque);
extern void d_push_back(Stack *stack, void *elem);
extern void d_push_front(Stack *stack, void *elem);
extern void d_pop_back(Deque *deque);
extern void d_pop_front(Deque *deque);
extern int d_back(Deque *deque);
extern void d_front(Deque *deque);
extern void d_empty(Deque *deque);
extern void d_free(Deque *deque);

#endif