#include <stdio.h>
#include "pq.h"
#include <string.h>

int main(){
    PQ *pq = init_pq(7, (int(*)(void *, void *))strcmp);
    push(&pq, "heloo");
    push(&pq, "awf");
    push(&pq, "howdy");
    push(&pq, "boaer");
    push(&pq, "xxy");
    push(&pq, "iasdf");
    push(&pq, "olaf");
    pq = reinit_pq(pq, 9);
    push(&pq, "diff");
    push(&pq, "yanking");
    //puts((char *)poll(&pq));
    //puts((char *)poll(&pq));
    //puts((char *)poll(&pq));
    //puts((char *)poll(&pq));
    //puts((char *)poll(&pq));
    //push(&pq, "zebra");
    //push(&pq, "yeexrt");
    //puts((char *)poll(&pq));
    //puts((char *)poll(&pq));
    //puts((char *)poll(&pq));
    free_queue(pq);
    return 0;
}
