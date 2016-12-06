#include <stdio.h>
#include "stack.h"

int main(){
    Stack *s = init_stack();
    push(&s, "howdy");
    push(&s, "howdy");
    push(&s, "howdy");
    pop(&s);
    push(&s, "howdy");
    push(&s, "howdy");
    pop(&s);
    free_stack(s);
    return 0;
}
void func(int index, void *val){
    printf("%d %s", index, (char *)val);
}
