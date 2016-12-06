#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

typedef struct{
    void *wrapper;
    //TODO header file for size_l
    int size;
}Stack;

Stack *init_stack();
int push(Stack **, void *val);
void *pop(Stack **);
void *peek(Stack *);
int size(Stack *);
int is_empty(Stack *);
void for_each(Stack *, void (*)(int index, void *val));
void free_stack(Stack *);

#endif
