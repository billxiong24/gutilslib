#ifndef PQ_H 
#define PQ_H 
#include "queue.h"

typedef struct {

    /*
     * include QUEUE struct as first element of struct
     * to include its functions (i.e. "implementing" the interface)
     * QUEUE element must be first element of struct so that
     * the address of struct aligns with QUEUE element. This is done
     * for casting purposes. 
     */
    QUEUE queue;

    /*
     * generic pointer to internal struct in pq.c,
     * effectively provides encapsulation at the cost
     * of type safety.
     */
    void *wrapper;
    int (*cmp)(void *, void *);
} PQ;

/* "constructor" to initalize members of struct */
PQ *init_pq(int size, int(*)(void *, void *));

/* Give user flexibility to resize priority queue */
void resize(PQ **, int size);

#endif 
