#include "arrlist.h"
#include <stdio.h>

int main(void) {
    ARR_LIST *list = init_arr_list(6);
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");
    LIST_APPEND(list, "howdy");

    LIST_FREE(list);
    
    return 0;
}
