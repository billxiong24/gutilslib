#include "arrlist.h"

struct arrlist {
    void **arr;
    int curr_index;
    int size;
};

void *arrlist_get(struct list *, int index);
void arrlist_sort(struct list *);
int arrlist_size(struct list *);
void arrlist_free(struct list *);
void arrlist_for_each(struct list *, void (*)(int index, void * val));
/*
 * These pass in double pointer to list in order to 
 * directly modify struct itself
 */
void arrlist_set(struct list **, void *val, int index);
int arrlist_insert(struct list **, void *val, int index); 
void arrlist_append(struct list **, void *val);
void *arrlist_remove(struct list **, int index); 
void arrlist_reverse(struct list **); 

ARR_LIST *init_arr_list(int size) {
    ARR_LIST *arr = malloc(sizeof(*arr));

    /* Initialize internal struct */
    arr->wrapper = malloc(sizeof(struct arrlist));
    struct arrlist *internal = (struct arrlist *) arr->wrapper;

    internal->curr_index = 0;
    internal->size = size;
    internal->arr = malloc(sizeof(void *) * (size + 1));

    /*
     * Implement LIST interface by assigning 
     * function pointers
     */
    
    arr->list.list_get = arrlist_get;
    arr->list.list_sort= arrlist_sort;
    arr->list.list_size = arrlist_size;
    arr->list.list_free = arrlist_free;
    arr->list.list_for_each = arrlist_for_each;
    arr->list.list_set = arrlist_set;
    arr->list.list_insert = arrlist_insert;
    arr->list.list_append = arrlist_append;
    arr->list.list_remove = arrlist_remove;
    arr->list.list_reverse = arrlist_reverse;

    return arr;
}

void *arrlist_get(struct list *list, int index) {
    ARR_LIST *arr = (ARR_LIST *) list;
    struct arrlist *internal = (struct arrlist *) arr->wrapper;
    return internal->arr[index];
}

void arrlist_sort(struct list *list) {

}

int arrlist_size(struct list *list) {
    ARR_LIST *arr = (ARR_LIST *) list;
    struct arrlist *internal = (struct arrlist *) arr->wrapper;
    return internal->curr_index;
}

void arrlist_free(struct list *list) {
    ARR_LIST *arr = (ARR_LIST *) list;
    struct arrlist *internal = (struct arrlist *) arr->wrapper;
    free(internal->arr);
    free(internal);
    free(arr);
}

void arrlist_for_each(struct list *list, void (*func)(int index, void * val)) {

}

void list_set(struct list **list, void *val, int index) {
    ARR_LIST **arr = (ARR_LIST **) list;
    struct arrlist **internal = (struct arrlist **) &(*arr)->wrapper;
    (*internal)->arr[index] = val;
}

int list_insert(struct list **list, void *val, int index) {

}
 
void list_append(struct list **list, void *val) {

}

void *list_remove(struct list **list, int index) {

}
 
void list_reverse(struct list **list) {

}
 
