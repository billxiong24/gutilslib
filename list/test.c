#include <stdio.h>
#include "list.h"
#include "l_iter.h"
int main(){
    List *list = init_list();
    append_list(&list, "hello world");
    append_list(&list, "wat");
    append_list(&list, "third");
    append_list(&list, "fourth");
    puts("hey no seg");
    print_list(list);
    remove_node(&list, 0);
    remove_node(&list, 2);
    print_list(list);
    insert_list(&list, "insert_list first", 0) ;
    insert_list(&list, "insert_list first again", 0);
    insert_list(&list, "insert_list second", 2);
    printf("%d\n", (int) size_list(list));
    puts((char *) get_list(list, 1));
    print_list(list);
    reverse_list(&list);
    puts("print_listing reverse");
    print_list(list);

    struct iter *iter = iter_init(list);
    puts("ITERATOR:");
    while(iter_has_next(iter)){
        char *s = iter_next(iter);
        puts(s);
    }
    iter_destroy(iter);
    free_list(list);
}
