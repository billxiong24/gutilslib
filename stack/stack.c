#include "stack.h"

struct stack{
    struct stack *next;
    void *val;
};

Stack *init_stack(){
    Stack *s = malloc(sizeof(*s));
    s->wrapper = NULL;
    s->size = 0;
}

int push_stack(Stack **s, void *val){
    (*s)->size++;
    if(!(*s)->wrapper){
        (*s)->wrapper = malloc(sizeof(struct stack));
        struct stack *stack = (struct stack *) (*s)->wrapper;
        stack->next = NULL;
        stack->val = val;
        return 1;
    }
    struct stack **stack = (struct stack **) &(*s)->wrapper;
    struct stack *new_node = malloc(sizeof(*new_node));
    new_node->val = val;
    new_node->next = *stack;
    *stack = new_node;
    return 1; 
}
void *pop_stack(Stack **s){
    (*s)->size = (*s)->size ? (*s)->size-1 : 0;
    struct stack **stack = (struct stack **) &(*s)->wrapper;
    void *ret = (*stack)->val;
    struct stack *to_free = *stack;
    *stack = (*stack)->next;
    free(to_free);
    return ret;
}
void *peek_stack(Stack *s){
    struct stack *stack = (struct stack *) s->wrapper;
    return stack->val;
}
int size_stack(Stack *s){
    return s->size; 
}
int is_empty_stack(Stack *s){
    return s->size == 0;
}
void for_each_stack(Stack *s, void (*func)(int index, void *val)){
    struct stack *stack = (struct stack *) s->wrapper;
    struct stack *trav = stack;
    for(int i = 0; trav; trav = trav->next, ++i){
        func(i, trav->val);
    }
}
void free_stack(Stack *s){
    struct stack *stack = (struct stack *) s->wrapper;
    struct stack *trav = stack;
    while(trav){
        struct stack * f = trav;
        trav = trav->next;
        free(f);
    }
    free(s);
}
