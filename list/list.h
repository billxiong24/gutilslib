#ifndef LIST_H 
#define LIST_H 
#include <stdlib.h>
/*
 * List interface, used to implement linked list, 
 * array list, etc.
 */
typedef struct list {

    /*
     * Function pointers constitute methods in the 
     * "interface." Implementing files will assign these
     * function pointers.
     */
    void *(*list_get)(struct list *, int index);
    void (*list_sort)(struct list *);
    int (*list_size)(struct list *);
    void (*list_free)(struct list *);
    void (*list_for_each)(struct list *, void (*)(int index, void * val));
    /*
     * These pass in double pointer to list in order to 
     * directly modify struct itself
     */
    void (*list_set)(struct list **, void *val, int index);
    int (*list_insert)(struct list **, void *val, int index); 
    void (*list_append)(struct list **, void *val);
    void *(*list_remove)(struct list **, int index); 
    void (*list_reverse)(struct list **); 
} LIST;

/*
 * Macro function definitions allow shortened access to interface 
 * functions. However, implementing structs should have a declaration
 * LIST list;
 * as the first element of the implementing struct.
 */

#define LIST_GET(imp, index) imp->list.list_get((struct list *) imp, index)
#define LIST_SET(imp, val, index) imp->list.list_set((struct list *) imp, val, index)
#define LIST_SORT(imp) imp->list.list_sort((struct list *) imp)
#define LIST_SIZE(imp) imp->list.list_size((struct list *) imp)
#define LIST_FOR_EACH(imp) imp->list.list_for_each((struct list *) imp)

#define LIST_INSERT(imp, val, index) imp->list.list_insert((struct list **) &imp, val, index)
#define LIST_APPEND(imp, val) imp->list.list_append((struct list **) &imp, val)
#define LIST_REMOVE(imp, index) imp->list.list_remove((struct list **) &imp, index)
#define LIST_REVERSE(imp) imp->list.list_reverse((struct list **) &imp)
#define LIST_FREE(imp) imp->list.list_free((struct list *) imp)

#endif 
