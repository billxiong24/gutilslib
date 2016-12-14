#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>

#ifdef size_l
#undef size_l
#endif
#define size_l unsigned long int

typedef struct{
    size_l size;
    void *wrapper;
    void *iterator;
} List;

List *init_list(); //good
int insert_list(List **, void *val, int index); //good
void append_list(List **, void *val);//good
void *remove_node(List **, int index); //good
void *get_list(List *, int index);
void reverse_list(List **); //good
void sort_list(List *);
size_l size_list(List *);//good

void for_each_list(List **list, void (*)(int, void *));
void for_each_arr_list(List *, void **,  void (*)(void **, int, void *));
void print_list(List *); //for debugging
void free_list(List *); //good


#endif
