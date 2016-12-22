#include "linked_iter.h"

struct index {
    struct node *curr_element;
    int size;
};

/* Implemented iterator functions */
struct iter *linked_get_iter(LINKED_LIST *);
struct node *linked_iter_next(struct iter *iter);
int linked_iter_has_next(struct iter *iter);
void linked_iter_destroy(struct iter *iter);

static void copy(void **arr, int index, void *val){
    arr[index] = val;
}

LINKED_ITER *init_linked_iter(LINKED_LIST *list) {

    LINKED_ITER *iterator= malloc(sizeof(*iterator));
    list->iterator = iterator;
    
    /* 
     * Initialize iterator->wrapper element to point to first 
     * element of list
     */
    iterator->wrapper = malloc(sizeof(struct index));
    struct index *ind = (struct index *) iterator->wrapper;
    ind->curr_element = list->wrapper;
    ind->size = list->size;
    /*
     * Implementing interface by assigning function pointers.
     * cast get_iter to avoid incompatable pointer warning 
     * TODO obvious type safety issue, need to fix, but idk how 
     */
    iterator->iter.iter_next = (void *(*)(struct iter *)) linked_iter_next; 
    iterator->iter.iter_has_next = linked_iter_has_next; 
    iterator->iter.iter_destroy = linked_iter_destroy; 
    return iterator;
}

struct node *linked_iter_next(struct iter *iter){

    /* Very ratchet but works */
    LINKED_ITER *iterator = (LINKED_ITER *) iter;
    struct index *current = (struct index *) iterator->wrapper;
    
    struct node *ret = current->curr_element;
    current->curr_element = current->curr_element->next;
    return ret;
}

int linked_iter_has_next(struct iter *iter){
    LINKED_ITER *iterator = (LINKED_ITER *) iter;
    struct index *current = (struct index *) iterator->wrapper;
    
    return current->curr_element != NULL;
}

void linked_iter_destroy(struct iter *iter){
    LINKED_ITER *iterator = (LINKED_ITER *) iter;

    free(iterator->wrapper);
    free(iterator);
}

