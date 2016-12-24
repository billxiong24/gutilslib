#ifndef ITER_H
#define ITER_H


#ifdef TYPE_CHECK

#undef TYPE_CHECK
#define TYPE_CHECK(var, type) {__typeof(var) *__var; __var = (type *) NULL;}
#endif    

/*
 * Iterator interface for different files to implement. 
 * Implementing structs should put this struct as the first
 * element of the struct for alignment/casting purposes. 
 */
typedef struct iter {
    
    void *(*iter_next)(struct iter *);
    int (*iter_has_next)(struct iter *);

    /* iter_remove needs to be implemented by linked, arraylist*/
    void *(*iter_remove)(struct iter *);
    void (*iter_destroy)(struct iter *iter);

} ITER;

/*
 * Macro defined functions for shorter access, at the
 * cost of type safety- TODO integrate macro typechecker
 */
#define ITER_NEXT(var) var->iter.iter_next((ITER *) var)
#define ITER_HAS_NEXT(var) var->iter.iter_has_next((ITER *) var)
#define ITER_DESTROY(var) var->iter.iter_destroy((ITER *) var)

#endif
