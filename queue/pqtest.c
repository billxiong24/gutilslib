#include <stdio.h>
#include "pq.h"
#include <string.h>

int main(){
    PQ *pq = init_pq(8, (int(*)(void *, void *))strcmp);
    push_pq(&pq, "heloo");
    push_pq(&pq, "awf");
    push_pq(&pq, "howdy");
    push_pq(&pq, "boaer");
    push_pq(&pq, "xxy");
    push_pq(&pq, "iasdf");
    push_pq(&pq, "olaf");
    reinit_pq(&pq, 10);
    push_pq(&pq, "diff");
    push_pq(&pq, "yanking");
    char *d = malloc(25);
    strncpy(d, "water", 5);
    d[5] = '\0';
    reinit_pq(&pq, 16);
    push_pq(&pq, d);
    puts((char *)poll_pq(&pq));
    puts((char *)poll_pq(&pq));
    puts((char *)poll_pq(&pq));
    puts((char *)poll_pq(&pq));
    puts((char *)poll_pq(&pq));
    push_pq(&pq, "zebra");
    push_pq(&pq, "yeexrt");
    puts((char *)poll_pq(&pq));
    puts((char *)poll_pq(&pq));
    puts((char *)poll_pq(&pq));
    free_queue(pq);
    free(d);
    return 0;
}
