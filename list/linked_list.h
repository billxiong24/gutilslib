#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef size_l
#undef size_l
#endif
#define size_l unsigned long int

typedef struct{

    /*
     * Include LIST variable as first element 
     * of struct so that it aligns with address
     * of struct. Acts as an "implementation" of LIST interface.
     */
    LIST list;
    size_l size;

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
} LINKED_LIST;

LINKED_LIST *init_list(); 
void for_each_arr_list(LINKED_LIST *, void **,  void (*)(void **, int, void *));
void print_list(LINKED_LIST *); 

#endif
