#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
//TODO reinit causes invalid read size 8 for some reason
typedef struct{
    void *head;
    int (*cmp)(void *, void *);
    //TODO header file for size_l
}PQ;

PQ *init_pq(int size, int (*)(void *, void *));
void reinit_pq(PQ **, int size);
void push(PQ **, void *val);
void *poll(PQ **);
void *peek(PQ *);
int size(PQ *);
int is_empty(PQ *);
void for_each(PQ *, void (*)(int index, void *val));
void free_queue(PQ *);
#endif
