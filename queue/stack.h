#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

typedef struct{
    void *wrapper;
    //TODO header file for size_l
    int size;
}Stack;

Stack *init_stack();
int push_stack(Stack **, void *val);
void *pop_stack(Stack **);
void *peek_stack(Stack *);
int size_stack(Stack *);
int is_empty_stack(Stack *);
void for_each_stack(Stack *, void (*)(int index, void *val));
void free_stack(Stack *);

#endif
