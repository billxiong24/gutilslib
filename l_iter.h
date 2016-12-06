#ifndef L_ITER_H
#define L_ITER_H
#include "list.h"

#ifdef TYPE_CHECK
#undef TYPE_CHECK
#define TYPE_CHECK(var, type) {__typeof(var) *__var; __var = (type *) NULL;}
#endif    
struct iter{
    void *curr_index;
};
struct iter *iter_init(List *list); 
void *iter_next(struct iter *);
int iter_has_next(struct iter *);
void iter_destroy(struct iter *iter);


#endif
