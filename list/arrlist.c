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

/* Static Functions*/
static void expand(ARR_LIST **, int size);

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
    ARR_LIST *arr = (ARR_LIST *) list;
    struct arrlist *internal = (struct arrlist *) arr->wrapper;
    
    for(int i = 0; i < internal->curr_index; ++i) {
        func(i, internal->arr[i]);
    }
}

void arrlist_set(struct list **list, void *val, int index) {
    ARR_LIST **arr = (ARR_LIST **) list;
    struct arrlist **internal = (struct arrlist **) &(*arr)->wrapper;
    (*internal)->arr[index] = val;
}

int arrlist_insert(struct list **list, void *val, int index) {
    ARR_LIST **arr = (ARR_LIST **) list;
    struct arrlist **internal = (struct arrlist **) &(*arr)->wrapper;

    //TODO add better error checking
    if(index < 0 || index >= (*internal)->curr_index) 
        return 0;

    if((*internal)->curr_index >= (*internal)->size - 1) {
        expand(arr, (*internal)->size * 2);
    }

    for(int i = (*internal)->curr_index; i >= index; --i) {
        (*internal)->arr[i] = (*internal)->arr[i-1];
    }
    
    ++(*internal)->curr_index;
    (*internal)->arr[index] = val;
    return 1; 
}
 
void arrlist_append(struct list **list, void *val) {
    ARR_LIST **arr = (ARR_LIST **) list;
    struct arrlist **internal = (struct arrlist **) &(*arr)->wrapper;

    (*internal)->arr[(*internal)->curr_index] = val;
    puts((char *) (*internal)->arr[(*internal)->curr_index]); 
    ++(*internal)->curr_index;
    
    if((*internal)->curr_index >= (*internal)->size - 1) {
        int new_size = (*internal)->size * 2;
        expand(arr, new_size);
    }
}

void *arrlist_remove(struct list **list, int index) {
    ARR_LIST **arr = (ARR_LIST **) list;
    struct arrlist **internal = (struct arrlist **) &(*arr)->wrapper;
    
    if(index < 0 || index >= (*internal)->curr_index) {
        return NULL;
    }

    void *ret = (*internal)->arr[index];

    for(int i = index; i < (*internal)->curr_index - 1; ++i) {
        (*internal)->arr[i] = (*internal)->arr[i + 1];
    }

    (*internal)->curr_index--;
    return ret;
}
 
void arrlist_reverse(struct list **list) {

}

static void expand(ARR_LIST **arr, int size) {
    struct arrlist **internal = (struct arrlist **) &(*arr)->wrapper;
    
    (*internal)->arr = realloc((*internal)->arr, (size + 1) * sizeof(void *));
    (*internal)->size = size;
}
