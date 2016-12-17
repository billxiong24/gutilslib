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
void push_queue(Queue **, void *val);
void *poll_queue(Queue **);
void *peek_queue(Queue *);
int size_queue(Queue *);
int is_empty_queue(Queue *);
void for_each_queue(Queue *, void (*)(int index, void *val));
void free_queue(Queue *);

#endif
