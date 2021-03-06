#ifndef ARRLIST_H
#define ARRLIST_H 

/* For debugging, remove later */
#include <stdio.h>
#include "list.h"

typedef struct{

    /*
     * Include LIST variable as first element 
     * of struct so that it aligns with address
     * of struct. Acts as an "implementation" of LIST interface.
     */
    LIST list;

    /* 
     * generic pointer to internal linked list, 
     * provides encapsulation
     */
    void *wrapper;

    /*
     * generic pointer to internal iterator struct,
     * encapsulation
     */
    void *iterator;
} ARR_LIST;

ARR_LIST *init_arr_list(int size);
void **arr_list_to_array(ARR_LIST *);

#endif 
