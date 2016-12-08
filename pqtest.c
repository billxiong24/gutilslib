#include <stdio.h>
#include "pq.h"
#include <string.h>

int main(){
    PQ *pq = init_pq((int(*)(void *, void *))strcmp);
    push(&pq, "hi");
    push(&pq, "wont work");
    push(&pq, "xray");
    push(&pq, "fourth");
    push(&pq, "zzzebra");

    push(&pq, "abre");

    puts((char *) peek(pq));

    return 0;
}
