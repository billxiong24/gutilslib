#ifndef STACK_H
#define STACK_H
#include "queue.h"
#include <stdlib.h>

typedef struct {

    /*
     * By including this element, we implement
     * the queue interface specified by queue.h
     * must be first element, so it aligns with the
     * address of the struct (for casting purposes)
     */
    QUEUE queue;

    /*
     * void pointer points to internal struct
     * in fifo_queue.c, hidden from user. provides
     * encapsulation. 
     */
    void *wrapper;

    /*TODO make this size_l in a header file or something*/
    int size;
} STACK;

/*
 * "constructor" for stack
 */
STACK *init_stack(void);

#endif 
