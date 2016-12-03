#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>

#ifdef size_l
#undef size_l
#endif
#define size_l unsigned long int

typedef struct{
    /*int (List **, *insert)(List **, void *val, int index);
    int (List **, *append)(List **, void *val);
    int (List **, *remove_node)(List **, void *val, int index);
    void (List **, *reverse)(List **, );
    void (List **, *sort)(List **, );
    void (List **, *print)(List **, );
    void (List **, *free_list)(List **, );*/
    size_l size;
    void *wrapper;
} List;

List *init_list(); //good
int insert(List **, void *val, int index); //good
void append(List **, void *val);//good
void *remove_node(List **, int index); //good
void *get(List *, int index);
void reverse(List **);
void sort(List *);
size_l size(List *);//good
void print(List *); //for debugging
void free_list(List *); //good


#endif
