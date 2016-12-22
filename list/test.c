#include <stdio.h>
#include "linked_iter.h"
#include "linked_list.h"
int main() {
    #ifdef __NODE_GUARD
    puts("defined");
    #endif
    struct node *s; 
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
    print_list(list);
    LINKED_ITER *iter = init_linked_iter(list);
    printf("list->iterator == NULL = %d\n", list->iterator == NULL);
    
    while(ITER_HAS_NEXT(iter)) {
        struct node *test = ITER_NEXT(iter);
        puts((char *) test->val);
    }
      
    ITER_DESTROY(iter);
    LIST_FREE(list);
    return 0;
}
