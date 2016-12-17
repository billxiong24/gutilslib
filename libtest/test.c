#include "sub.h"

int main(int argc, const char *argv[]){
    ST *st = construct(); 
    int a = ST(st, func1)(5, 6);
    F2(st);
    printf("a = %d\n", a);
    int c = size(st);
    printf("c = %d\n", c);
    ST_INIT(st);
    return 0;
}
