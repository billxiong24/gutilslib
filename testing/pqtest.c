#include <stdio.h>
#include "pq.h"
#include <string.h>
int main(void) {
    PQ *pq = init_pq(4, (int (*)(void *, void *)) strcmp); 
    PUSH(pq, "hello");
    PUSH(pq, "asdf");
    PUSH(pq, "baby");
    resize(&pq, 7);
    PUSH(pq, "iworld");
    PUSH(pq, "iworld");
    PUSH(pq, "watj");
    resize(&pq, 9);
    PUSH(pq, "jkjk");
    PUSH(pq, "fdas");
    puts((char *)POLL(pq));
    puts((char *)POLL(pq));
    puts((char *)POLL(pq));
    puts((char *)POLL(pq));
    puts((char *)POLL(pq));
    //PUSH(pq, "world");
    //puts((char *) PEEK(pq));
    FREE_Q(pq);
    return 0;
}
