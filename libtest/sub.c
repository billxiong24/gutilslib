#include "sub.h"

struct stack{
    int size;
};
int f1(int, int);
void f2(ST **);
void init();

ST *construct(){
    ST *st = malloc(sizeof(*st));
    st->wrapper = malloc(sizeof(struct stack));
    struct stack *stack = (struct stack *) st->wrapper;
    st->queue.func1 = f1;
    st->queue.func2 = (void(*)(queue **)) f2;
    st->queue.init = init;
    stack->size = 0;
    return st;
}

int f1(int a, int b){
    return a + b;
}
void f2(ST ** st){
    struct stack *stack = (struct stack *) (*st)->wrapper;
    stack->size = 20;
}
void init(){
    puts("inited");
}
int size(ST *st){
    struct stack *stack = (struct stack *) (st)->wrapper;
    return stack->size;    
}
