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
    
    puts((char *) poll(&pq));
    puts((char *) poll(&pq));
    puts((char *) poll(&pq));
    push(&pq, "test");
    push(&pq, "fdsa");
    push(&pq, "zelda");
    puts((char *) poll(&pq));
    puts((char *) poll(&pq));
    puts((char *) poll(&pq));
    push(&pq, "zelda");
    puts((char *) poll(&pq));
    return 0;
}
