#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>

typedef struct{
    void *head;
    void *tail;
    //TODO header file for size_l
    int size;
}Queue;

Queue *init_queue();
void push(Queue **, void *val);
void *poll(Queue **);
void *peek(Queue *);
int size(Queue *);
int is_empty(Queue *);
void for_each(Queue *, void (*)(int index, void *val));
void free_queue(Queue *);

#endif
