#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    void *head;
    int (*cmp)(void *, void *);
    //TODO header file for size_l
    int size;
    int num;
}PQ;

PQ *init_pq(int (*)(void *, void *));
void push(PQ **, void *val);
void *poll(PQ **);
void *peek(PQ *);
int size(PQ *);
int is_empty(PQ *);
void for_each(PQ *, void (*)(int index, void *val));
void free_queue(PQ *);

#endif
