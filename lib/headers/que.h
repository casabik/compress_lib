#ifndef QUE_H
#define QUE_H

#include <stdlib.h>
#include "../headers/list.h"

/*typedef struct L2Node {
    int data;
    struct L2Node *prev;
    struct L2Node *next;
} L2Node;
 
typedef struct L2 {
    struct L2Node *head;
    struct L2Node *tail;
    size_t size;
} L2;*/

typedef L2 Stack;
typedef L2 Queue;
typedef L2 Deque;


extern void s_push_back(Stack *stack, int elem);
extern int s_pop(Stack *stack);
extern int s_top(Stack *stack);
extern int s_empty(Stack *stack);
extern int s_size(Stack *stack);
extern void s_free(Stack *stack);
extern void s_printf(Stack *stack);

extern void enqueue(Queue *queue, int elem);
extern int dequeue(Queue *queue);
extern int q_empty(Queue *qeque);
extern int q_top(Queue *qeque);
extern int q_size(Queue *qeque);
extern void q_free(Queue *queue);
extern void q_printf(Queue *queue);

extern void d_push_back(Deque *deque, int elem);
extern void d_push_front(Deque *deque, int elem);
extern int d_pop_back(Deque *deque);
extern int d_pop_front(Deque *deque);
extern int d_back(Deque *deque);
extern int d_size(Deque *deque);
extern int d_front(Deque *deque);
extern int d_empty(Deque *deque);
extern void d_printf(Deque *deque);
extern void d_free(Deque *deque);

#endif