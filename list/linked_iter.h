#ifndef LINKED_ITER_H
#define LINKED_ITER_H 
#define __NODE_GUARD

#include "iter.h"
#include "linked_list.h"
typedef struct linked_iter {

    /*
     * Implementation of iterator "interface"
     * Include as first element for alignment/casting
     * purposes. 
     */
    ITER iter;

    /*
     * Wrapper to internal struct, provides encapsulation.
     */
    void *wrapper;
     
} LINKED_ITER;

/* "Constructor" */
LINKED_ITER *init_linked_iter(LINKED_LIST *);

#undef __NODE_GUARD
#endif 
