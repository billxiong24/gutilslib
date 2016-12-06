#ifndef L_ITER_H
#define L_ITER_H
#include "list.h"
#define TYPE_CHECK(var, type) {__typeof(var) *__var; __var = (type *) NULL;}
    
struct iter{
    void *curr_index;
};
struct iter *iter_init(List *list); 
void *iter_next(struct iter *);
int iter_has_next(struct iter *);
void iter_destroy(struct iter *iter);


#endif
