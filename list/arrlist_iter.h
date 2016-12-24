#ifndef ARRLIST_ITER_H
#define ARRLIST_ITER_H

#include "iter.h"
#include "arrlist.h"
typedef struct {

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

} ARR_LIST_ITER;

/* "Constructor" */
ARR_LIST_ITER *init_arrlist_iter(ARR_LIST *);

#endif 
