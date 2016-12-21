#include "stack.h"

struct stack {
    struct stack*next;
    void *val;
};

void stack_push(QUEUE **queue, void *val);
void *stack_poll(QUEUE **);
void *stack_peek(QUEUE *);
int stack_size(QUEUE *);
int stack_empty(QUEUE *);
void stack_for_each(QUEUE *, void (*)(int index, void *val));
void stack_free(QUEUE *);

/* static functions */
static struct stack *new_node(void * val);

STACK *init_stack(void) {
    STACK *stack = malloc(sizeof(*stack));
    stack->size = 0;
    stack->wrapper = NULL;

    /* Implement queue interface by assigning function pointers */
    stack->queue.push = stack_push;
    stack->queue.poll = stack_poll;
    stack->queue.peek = stack_peek;
    stack->queue.size = stack_size;
    stack->queue.is_empty = stack_empty;
    stack->queue.for_each_queue = stack_for_each;
    stack->queue.free_queue =  stack_free;
    return stack;
}
void stack_push(QUEUE **queue, void *val) {
    STACK **s = (STACK **) queue;
    (*s)->size++;

    if(!(*s)->wrapper) {
        (*s)->wrapper = malloc(sizeof(struct stack));
        /*
         * cast wrapper into internal struct to access and
         * manipulate elements
         */
        struct stack *stack = (struct stack *) (*s)->wrapper;
        stack->next = NULL; 
        stack->val = val;
        return;
    }
    struct stack **stack = (struct stack **) &(*s)->wrapper;
    struct stack *node = new_node(val);
    node->next = *stack;
    *stack = node;
}

void *stack_poll(QUEUE **queue) {
    STACK **s = (STACK **) queue;
    (*s)->size--;

    /*
     * extra level of indirection in order to "permanently
     * modify contents of struct
     */
    struct stack **stack = (struct stack **) &(*s)->wrapper;
    void *ret = (*stack)->val;
    struct stack *to_free = *stack;
    *stack = (*stack)->next;
    free(to_free);
    return ret;
}

void *stack_peek(QUEUE *queue) {
    STACK *s = (STACK *) queue;
    struct stack *stack = (struct stack *) s->wrapper;
    return stack->val;
}

int stack_size(QUEUE *queue) {
    STACK *s = (STACK *) queue;
    return s->size;
}

int stack_empty(QUEUE *queue) {
    return stack_size(queue) == 0;
}

void stack_for_each(QUEUE *queue, void (*func)(int index, void *val)) {
    STACK *s = (STACK *) queue;
    struct stack *stack = (struct stack *) s->wrapper;
    register int index = 0;

    for(struct stack *trav = stack; trav; trav = trav->next, ++index) {
        func(index, trav->val);
    }
}

void stack_free(QUEUE *queue) {
    STACK *s = (STACK *) queue;
    struct stack *stack = (struct stack *) s->wrapper;
    struct stack *trav = stack;

    while(trav) {
        struct stack *f = trav;
        trav = trav->next;
        free(f);
    }
    free(s);
}

static struct stack *new_node(void *val) {
    struct stack *node = malloc(sizeof(*node));
    node->next = NULL;
    node->val = val;
    return node;
}
