#include <stdio.h>
#include "queue.h"
void func(int index, void *val);
int main(){
    Queue *queue = init_queue();
    push(&queue, "hello world");
    push(&queue, "second");
    push(&queue, "third");
    poll(&queue);
    puts((char *) poll(&queue));
    puts((char *) peek(queue));
    for_each(queue, func);
    free_queue(queue);
    return 0;
}

void func(int index, void *val){
    printf("%d %s \n", index, (char *) val);
}
