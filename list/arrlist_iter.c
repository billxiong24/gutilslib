#include "arrlist_iter.h"

struct index {
    int curr_index, size;
    const ARR_LIST *list;
};

/* Implementing functions */
void *arrlist_iter_next(struct iter *);
void *arrlist_iter_remove(struct iter *);
int arrlist_iter_has_next(struct iter *);
void arrlist_iter_destroy(struct iter *);
    
ARR_LIST_ITER *init_arrlist_iter(ARR_LIST *arr) {
    ARR_LIST_ITER *iter = malloc(sizeof(*iter));
    iter->wrapper = malloc(sizeof(struct index));
    struct index *iterator = (struct index *) iter->wrapper;
     
    /* Initialize iterator elements */

    iterator->curr_index = 0;
    iterator->size = LIST_SIZE(arr);
    iterator->list = arr; 

    /* Implement ITER interface by assigning function pointers*/
    iter->iter.iter_next = arrlist_iter_next;
    iter->iter.iter_remove = arrlist_iter_remove;
    iter->iter.iter_has_next = arrlist_iter_has_next;
    iter->iter.iter_destroy = arrlist_iter_destroy;
    return iter;
}

void *arrlist_iter_next(struct iter *iterator) {
    ARR_LIST_ITER *iter = (ARR_LIST_ITER *) iterator;
    struct index *ind = (struct index *) iter->wrapper;
    
    //TODO fix error handling
    if(ind->curr_index >= ind->size)
        return NULL;

    return LIST_GET(ind->list, ind->curr_index++);
}

void *arrlist_iter_remove(struct iter *iterator) {
    ARR_LIST_ITER *iter = (ARR_LIST_ITER *) iterator;
    struct index *ind = (struct index *) iter->wrapper;
    
    if(ind->curr_index >= ind->size) 
        return NULL;
    
    return LIST_REMOVE(ind->list, ind->curr_index);
}

int arrlist_iter_has_next(struct iter *iterator) {
    ARR_LIST_ITER *iter = (ARR_LIST_ITER *) iterator;
    struct index *ind = (struct index *) iter->wrapper;
    return ind->curr_index < ind->size;     
}

void arrlist_iter_destroy(struct iter *iterator) {
    ARR_LIST_ITER *iter = (ARR_LIST_ITER *) iterator;
    free(iter->wrapper);
    free(iter);
}

