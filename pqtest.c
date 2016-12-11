#include <stdio.h>
#include "pq.h"
#include <string.h>

int main(){
    PQ *pq = init_pq(3, (int(*)(void *, void *))strcmp);
    push(&pq, "heloo");
    push(&pq, "awf");
    push(&pq, "howdy");
    push(&pq, "boaer");
    push(&pq, "xxy");
    push(&pq, "iasdf");
    push(&pq, "iasdf");
    push(&pq, "iasdf");
    push(&pq, "iasdf");
    push(&pq, "iasdf");
    push(&pq, "iasdf");
    push(&pq, "olaf");
    puts((char *)poll(&pq));
    puts((char *)poll(&pq));
    puts((char *)poll(&pq));
    puts((char *)poll(&pq));
    puts((char *)poll(&pq));
    push(&pq, "zebra");
    push(&pq, "yeexrt");
    puts((char *)poll(&pq));
    puts((char *)poll(&pq));
    free_queue(pq);
    return 0;
}
