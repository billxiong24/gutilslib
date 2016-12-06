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
int insert(List **, void *val, int index); //good
void append(List **, void *val);//good
void *remove_node(List **, int index); //good
void *get(List *, int index);
void reverse(List **); //good
void sort(List *);
size_l size(List *);//good

void for_each(List **list, void (*)(int, void *));
void for_each_arr(List *, void **,  void (*)(void **, int, void *));
void print(List *); //for debugging
void free_list(List *); //good


#endif
