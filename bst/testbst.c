#include "bst.h"
#include <stdio.h>
#include <string.h>
int main(){
    BST *bst = init_bst((int(*)(void *, void *))strcmp);
    insert_bst(&bst, "howdy");
    insert_bst(&bst, "apple");
    insert_bst(&bst, "iter");
    printf("%d \n", contains_bst(bst, "iter"));
    printf("%d \n", contains_bst(bst, "asdf"));
    print(bst);
    free_bst(bst);
    return 0;
}
