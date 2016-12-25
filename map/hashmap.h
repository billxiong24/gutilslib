#ifndef HASHMAP_H
#define HASHMAP_H

#define __PAIR_GUARD
#include "map.h"
#include "pair_p.h"

typedef unsigned int (*hash_func)(void *);
typedef struct {
    
    /*
     * Effectively implements MAP interface by
     * including the struct as the first element
     * of this struct. It is required to be the
     * first element because of casting and alignment
     * purposes.
     */
    MAP map;

    /*
     * Wrapper to internal struct, provides 
     * encapsulation
     */
    void *wrapper;

    int size;
} HASHMAP;

HASHMAP *init_hashmap(int size, float load, hash_func);

#undef __PAIR_GUARD
#endif 
