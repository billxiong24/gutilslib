#ifndef MAP_H
#define MAP_H

#include <stdlib.h>

/*
 * MAP interface containing methods that will be
 * implemented by map data structures, such as
 * hashmap and treemap.
 */
typedef struct map {

    /* 
     * Require double pointer because directly
     * modifying contents of struct
     */
    void (*put)(struct map **, void *, void *);
    void (*remove)(struct map **, void *);
    
    /* Only require single pointer */
    void *(*get)(struct map *, void *);
    int (*size)(struct map *);
    
    /* Requires an implementation of a hash function */
    unsigned int (*hash)(void *);
} MAP;

/*
 * Macro definitions of above functions allow shorter and easier access, 
 * imitating behavior of a true interface. Use these macros when calling
 * interface functions.
 */
#define MAP_PUT(imp, key, val) imp->map.put((struct map **) &imp, key, val)
#define MAP_REMOVE(imp, key) imp->map.remove((struct map **) &imp, key)
#define MAP_GET(imp, key) imp->map.get((struct map *) imp, key)
#define MAP_SIZE(imp) imp->map.size((struct map *) imp)

#endif 
