#include "stack.h"
#include <stdio.h>

int main(void) {
    STACK *st = init_stack(); 
    PUSH(st, "wat");
    PUSH(st, "howdy");
    PUSH(st, "uaoeri");
    puts((char *) PEEK(st));
    char *t = POLL(st);
    puts(t);
    PUSH(st, "ityuo");
    puts((char *) PEEK(st));
    PUSH(st, "howdy");
    t = POLL(st);
    puts(t);
    printf("SIZE(st) = %d\n", SIZE(st));
    FREE_Q(st);
    return 0;
}
