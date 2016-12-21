#include "queue.h"
#include "fifo_queue.h"
#include "stack.h"
#include <stdio.h>
void func(int index, void *val);
int main(void) {
    STACK *stack = init_stack();
    FIFO_QUEUE *queue = init_queue(); 
    PUSH(queue, "hello");
    PUSH(queue, "wat");
    PUSH(queue, "hey");
    PUSH(queue, "word");
    PUSH(stack, "stack");
    PUSH(stack, "ipan");
    puts((char *) PEEK(queue));
    FOR_EACH(queue, func);
    puts((char *) POLL(queue));
    puts((char *) PEEK(queue));
    puts((char *) POLL(queue));
    puts((char *) POLL(stack));
    puts((char *) POLL(queue));
    puts((char *) POLL(queue));
    FREE_Q(queue);
    FREE_Q(stack);
    return 0;
}
void func(int index, void *val) {
    printf("index = %d %s\n", index, (char *) val);
}
