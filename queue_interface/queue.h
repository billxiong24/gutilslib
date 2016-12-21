#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
/*
 * queue interface for implementing different types of queues,
 * such as fifo queue, stack, priority queue, binomial queue, etc.
 * functions are wrapped in a struct which is included as a member
 * of the implementing header file's struct.
 */
typedef struct queue {

    /*
     * double pointer for extra level of indirection so we can 
     * modify the actual contents of the queue
     */
    void (*push)(struct queue **, void *val);
    void *(*poll)(struct queue **);
    
    /*double pointer not necessary here */
    void *(*peek)(struct queue *);
    int (*size)(struct queue *);
    int (*is_empty)(struct queue *);
    
    /*
     * rudimentary for_each iterator 
     * TODO make iterator interface
     */
    void (*for_each_queue)(struct queue *, void (*)(int index, void *val));
    void (*free_queue)(struct queue *);
} QUEUE;

/*
 * macro defined functions for shorter access.
 * Instead of st->queue.func(), do FUNC_ST(st, ...);
 */

#define PUSH(st, var) (st)->queue.push((QUEUE **) &st, var)
#define POLL(st) (st)->queue.poll((QUEUE **) &st)
#define PEEK(st) (st)->queue.peek((QUEUE *) st)
#define SIZE(st) (st)->queue.size((QUEUE *) st)
#define IS_EMPTY(st) (st)->queue.is_empty((QUEUE *) st)
#define FOR_EACH(st, var) (st)->queue.for_each_queue((QUEUE *) st, var)
#define FREE_Q(st) (st)->queue.free_queue((QUEUE *) st)

#endif 
