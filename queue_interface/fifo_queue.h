#ifndef FIFO_QUEUE_H
#define FIFO_QUEUE_H
#include "queue.h"
typedef struct {
    
    /*
     * By including this element, we implement
     * the queue interface specified by queue.h
     * must be first element, so it aligns with the
     * address of the struct (for casting purposes)
     */
    QUEUE queue;

    /*
     * 2 void pointers point to front and end of internal
     * linked list in fifo_queue.c to provide encapsulation.
     */
    void *head, *tail;

    /*TODO header file for size_l*/
    int size;
} FIFO_QUEUE;

/* "constructor" for fifo_queue*/
FIFO_QUEUE *init_queue(void);

#endif 
