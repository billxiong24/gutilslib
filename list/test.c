#include <stdio.h>
#include "linked_list.h"
int main(){
    LINKED_LIST *list = init_list();
    LIST_INSERT(list, "wat", 0);
    LIST_APPEND(list, "hello");
    LIST_APPEND(list, "hello");
    LIST_APPEND(list, "hello");
    LIST_APPEND(list, "hello");
    LIST_INSERT(list, "fourth?", 3);
    LIST_INSERT(list, "fifth?", 2);
    LIST_REMOVE(list, 2);
    LIST_REMOVE(list, 2);
    LIST_REVERSE(list);

    puts((char *) LIST_GET(list, 1));
    printf("LIST_SIZE(list) = %d\n", LIST_SIZE(list));
    print_list(list);
    LIST_FREE(list);
    return 0;
}
