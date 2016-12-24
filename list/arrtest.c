#include "arrlist.h"
#include "arrlist_iter.h"
#include <stdio.h>

void print(int index, void *val);
int main(void) {
    ARR_LIST *list = init_arr_list(14);
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");
    printf("LIST_SIZE(list) = %d\n", LIST_SIZE(list));
    LIST_APPEND(list, "howdy");
    printf("LIST_SIZE(list) = %d\n", LIST_SIZE(list));
    LIST_APPEND(list, "last");
    printf("LIST_SIZE(list) = %d\n", LIST_SIZE(list));
    LIST_REMOVE(list, 2);
    printf("LIST_SIZE(list) = %d\n", LIST_SIZE(list));
    LIST_REMOVE(list, 2);
    printf("LIST_SIZE(list) = %d\n", LIST_SIZE(list));
    LIST_INSERT(list, "risky", 2);
    printf("LIST_SIZE(list) = %d\n", LIST_SIZE(list));
    puts("For each");
    LIST_FOR_EACH(list, print);

    puts("ITERATOR TEST");
    ARR_LIST_ITER *iterator = init_arrlist_iter(list);

    while(ITER_HAS_NEXT(iterator)) {
        puts((char *) ITER_NEXT(iterator));
    }
    ITER_DESTROY(iterator);
    LIST_FREE(list);
    
    return 0;
}

void print(int ind, void *val) {
    printf("ind = %d\n", ind);
    puts((char *) val);
}
