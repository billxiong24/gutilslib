#include <stdio.h>
#include "list.h"
#include "l_iter.h"
int main(){
    List *list = init_list();
    append(&list, "hello world");
    append(&list, "wat");
    append(&list, "third");
    append(&list, "fourth");
    puts("hey no seg");
    print(list);
    remove_node(&list, 0);
    remove_node(&list, 2);
    print(list);
    insert(&list, "insert first", 0) ;
    insert(&list, "insert first again", 0);
    insert(&list, "insert second", 2);
    printf("%d\n", (int) size(list));
    puts((char *) get(list, 1));
    print(list);
    reverse(&list);
    puts("printing reverse");
    print(list);
    struct iter *iter = iter_init(list);
    puts("ITERATOR:");
    while(iter_has_next(iter)){
        char *s = iter_next(iter);
        puts(s);
    }
    iter_destroy(iter);
    free_list(list);
}
