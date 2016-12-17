#include <stdio.h>
#include "pq.h"
#include <string.h>

int main(){
    PQ *pq = init_pq(8, (int(*)(void *, void *))strcmp);
//    push(&pq, "heloo");
//    push(&pq, "awf");
//    push(&pq, "howdy");
//    push(&pq, "boaer");
//    push(&pq, "xxy");
//    push(&pq, "iasdf");
//    push(&pq, "olaf");
//    reinit_pq(&pq, 10);
//    push(&pq, "diff");
//    push(&pq, "yanking");
//    char *d = malloc(25);
//    strncpy(d, "water", 5);
//    d[5] = '\0';
//    reinit_pq(&pq, 16);
//    push(&pq, d);
//    puts((char *)poll(&pq));
//    puts((char *)poll(&pq));
//    puts((char *)poll(&pq));
//    puts((char *)poll(&pq));
//    puts((char *)poll(&pq));
//    push(&pq, "zebra");
//    push(&pq, "yeexrt");
//    puts((char *)poll(&pq));
//    puts((char *)poll(&pq));
//    puts((char *)poll(&pq));
//    free_queue(pq);
//    free(d);
    return 0;
}
