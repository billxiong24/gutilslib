#ifndef QUEUE_H
#define QUEUE_H
#include "queue.h"
#include <stdlib.h>

//TODO reinit causes invalid read size 8 for some reason
typedef struct{
    void *head;
    int (*cmp)(void *, void *);
    //TODO header file for size_l
}PQ;

PQ *init_pq(int size, int (*)(void *, void *));
void reinit_pq(PQ **, int size);
void push_pq(PQ **, void *val);
void *poll_pq(PQ **);
void *peek_pq(PQ *);
int size_pq(PQ *);
int is_empty_pq(PQ *);
void for_each_pq(PQ *, void (*)(int index, void *val));
void free_queue(PQ *);
#endif
